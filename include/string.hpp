#ifndef _OSL_STRING_HPP_
#define _OSL_STRING_HPP_

# include <memory.hpp>
# include <allocator.hpp>

OSL_BEGIN_NAMESPACE

template <class _Type, class _Allocator = allocator<_Type>>
class basic_string : public _Allocator
{
public:

    using type = _Type;
    using size_type = typename _Allocator::size_type;

    basic_string() _OSL_NOEXCEPT : _len(0), _Allocator() { }

    virtual ~basic_string()
    {
        clear();
    }

    basic_string(const type obj) _OSL_NOEXCEPT : _len(1), _Allocator(2)
    {
        this->_ptr[0] = obj;
        this->_ptr[1] = 0;
    }

    basic_string(const type *ptr) : _len(string_length(ptr)), _Allocator()
    {
        if (_len)
        {
            this->allocate(_len + 1);
        }

        memory_copy<type>(this->_ptr, ptr, _len);
        this->_ptr[_len] = 0;
    }

    basic_string(const basic_string &obj) : _len(obj.length()), _Allocator()
    {
        if (_len)
        {
            this->allocate(_len + 1);
        }

        memory_copy<type>(this->_ptr, obj.c_str(), _len);
        this->_ptr[_len] = 0;
    }

    basic_string &operator=(const type obj)
    {
        _len = 1;
        this->allocate(2);
        this->_ptr[0] = obj;
        this->_ptr[1] = 0;
        return *this;
    }

    basic_string &operator=(const type *ptr)
    {
        _len = string_length(ptr);
        size_type needed_size = _len + 1;

        if (this->_size < needed_size)
        {
            this->reallocate(needed_size);
        }

        memory_copy<type>(this->_ptr, ptr, _len);
        this->_ptr[_len] = 0;
        return *this;
    }

    basic_string &operator=(const basic_string &obj)
    {
        _len = obj.length();

        if (this->_size < _len + 1)
        {
            this->reallocate(_len + 1);
        }

        memory_copy<type>(this->_ptr, obj.c_str(), _len);
        this->_ptr[_len] = 0;
        return *this;
    }

    basic_string &operator+=(const type obj)
    {
        if (this->_size < _len + 2)
        {
            this->reallocate(_len + 2);
        }

        memory_set<type>(this->_ptr + _len, obj, 1);
        this->_ptr[++_len] = 0;
        return *this;
    }

    basic_string &operator+=(const type *ptr)
    {
        size_type len = string_length(ptr), new_len = _len + len;

        if (this->_size < new_len + 1)
        {
            this->reallocate(new_len + 1);
        }

        memory_copy<type>(this->_ptr + _len, ptr, len);
        this->_ptr[_len = new_len] = 0;
        return *this;
    }

    basic_string &operator+=(const basic_string &obj)
    {
        size_type len = obj.length(), new_len = _len + len;

        if (this->_size < new_len + 1)
        {
            this->reallocate(new_len + 1);
        }

        memory_copy<type>(this->_ptr + _len, obj.c_str(), len);
        this->_ptr[_len = new_len] = 0;
        return *this;
    }

    _OSL_NODISCARD basic_string &operator+(const type obj)
    {
        return this->operator+=(obj), *this;
    }

    _OSL_NODISCARD basic_string &operator+(const type *ptr)
    {
        return this->operator+=(ptr), *this;
    }

    _OSL_NODISCARD basic_string &operator+(const basic_string &obj)
    {
        return this->operator+=(obj), *this;
    }

    _OSL_NODISCARD bool operator==(const type obj)
    {
        if (_len != 1) return false;
        return *this->_ptr == obj;
    }

    _OSL_NODISCARD bool operator==(const type *ptr)
    {
        return string_compare(this->_ptr, const_cast<char*>(ptr));
    }

    _OSL_NODISCARD bool operator==(const basic_string &obj)
    {
        return string_compare(this->_ptr, const_cast<char*>(obj.c_str()));
    }

    _OSL_NODISCARD bool operator!=(const type obj)
    {
        return !(*this == obj);
    }

    _OSL_NODISCARD bool operator!=(const type *ptr)
    {
        return !(*this == ptr);
    }

    _OSL_NODISCARD bool operator!=(const basic_string &obj)
    {
        return !(*this == obj);
    }

    void clear()
    {
        _len = 0;
        this->free();
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE const type *c_str() const _OSL_NOEXCEPT
    {
        return this->_ptr;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE size_type length() const _OSL_NOEXCEPT
    {
        return _len;
    }

protected:

    size_type _len;

};

OSL_END_NAMESPACE

#endif
