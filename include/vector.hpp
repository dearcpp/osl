#ifndef _OSL_VECTOR_HPP_
#define _OSL_VECTOR_HPP_

# include <defines.hpp>
# include <allocator.hpp>
# include <int_types.hpp>

# include <initializer_list>

OSL_BEGIN_NAMESPACE

template <class _Type>
class vector_allocator : public allocator<_Type>
{
public:

    using type = _Type;
    using allocator<_Type>::allocator;
    using size_type = typename allocator<_Type>::size_type;

    virtual ~vector_allocator() { }

    virtual void sized_reallocate(size_type size, size_type destination_offset = 0, size_type source_offset = 0, size_type length = 0)
    {
        type *old_ptr = this->_ptr;
        this->_ptr = new type[size];
        if (old_ptr)
        {
            memory_copy(this->_ptr + destination_offset, old_ptr + source_offset, length);
            delete[] old_ptr;
        }
        this->_size = size;
    }

};

template <class _Type, class _Allocator = vector_allocator<_Type>>
class vector : public _Allocator
{
public:

    using type = _Type;
    using size_type = typename _Allocator::size_type;
    using initializer_list = std::initializer_list<_Type>;

    vector() _OSL_NOEXCEPT : _Allocator(), _len(0) { }

    vector(initializer_list list) : _Allocator(list.size()), _len(list.size())
    {
        for (size_type i = 0; i < _len; ++i)
        {
            this->operator[](i) = list.begin()[i];
        }
    }

    vector(const vector &vector) : _Allocator(), _len(0)
    {
        for (size_type it = 0; it < vector.length(); ++it)
        {
            push_back(vector[it]);
        }
    }

    virtual ~vector() { }

    void push_front(const type &value)
    {
        if (this->allocated() < ++_len)
        {
            this->sized_reallocate(_len, 1, 0, this->_len - 1);
        }
        this->operator[](0) = value;
    }

    void push_back(const type &value)
    {
        _len++;

        if (this->allocated() < _len)
        {
            this->reallocate(_len);
        }

        this->operator[](_len - 1) = value;
    }

    void pop_front()
    {
        _len--, this->sized_reallocate(_len, 0, 1, _len);
    }

    void pop_back()
    {
        _len--, this->sized_reallocate(_len, 0, 0, _len);
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE _Type back() const _OSL_NOEXCEPT
    {
        return this->_ptr[_len - 1];
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE _Type front() const _OSL_NOEXCEPT
    {
        return this->_ptr[0];
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
