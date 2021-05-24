#ifndef _OSL_STRING_HPP
#define _OSL_STRING_HPP

# include <memory.hpp>
# include <allocator.hpp>

OSL_BEGIN_NAMESPACE

template <class _Type, class _Allocator = allocator<_Type>>
class basic_string : public _Allocator
{
public:

    using type = _Type;

    basic_string() _OSL_NOEXCEPT { }

    virtual ~basic_string() _OSL_NOEXCEPT {
        clear();
    }

    basic_string(const type object) : _length(1) {
        this->allocate(2);
        this->_pointer[0] = object;
        this->_pointer[1] = 0;
    }

    basic_string(const type *pointer) : _length(string_length(pointer)) {
        this->allocate(_length + 1);
        memory_copy<type>(this->_pointer, pointer, _length);
        this->_pointer[_length] = 0;
    }

    basic_string(const basic_string &object) : _length(object.length()) {
        this->allocate(_length + 1);
        memory_copy<type>(this->_pointer, object.c_str(), _length);
        this->_pointer[_length] = 0;
    }

    basic_string &operator=(const type object) {
        _length = 1;
        this->allocate(2);
        this->_pointer[0] = object;
        this->_pointer[1] = 0;
    }

    basic_string &operator=(const type *pointer) {
        _length = string_length(pointer);

        if (this->_allocated < _length + 1)
            this->reallocate(_length + 1);

        memory_copy<type>(this->_pointer, pointer, _length);
        return this->_pointer[_length] = 0, *this;
    }

    basic_string &operator=(const basic_string &object) {
        _length = object.length();

        if (this->_allocated < _length + 1)
            this->reallocate(_length + 1);

        memory_copy<type>(this->_pointer, object.c_str(), _length);
        return this->_pointer[_length] = 0, *this;
    }

    basic_string &operator=(basic_string&& object) {
        this->_pointer = object.c_str();
        return object.clear(), *this;
    }

    basic_string &operator+=(const type object) {
        if (this->_allocated < _length + 2)
            this->reallocate(_length + 2);

        memory_set<type>(this->_pointer + _length, object, 1);
        return this->_pointer[++_length] = 0, *this;
    }

    basic_string &operator+=(const type *pointer) {
        u32 length = string_length(pointer);
        u32 new_length = _length + length;

        if (this->_allocated < new_length + 1)
            this->reallocate(new_length + 1);

        memory_copy<type>(this->_pointer + _length, pointer, length);
        return this->_pointer[_length = new_length] = 0, *this;
    }

    basic_string &operator+=(const basic_string &object) {
        u32 length = object.length();
        u32 new_length = _length + length;

        if (this->_allocated < new_length + 1)
            this->reallocate(new_length + 1);

        memory_copy<type>(this->_pointer + _length, object.c_str(), length);
        return this->_pointer[_length = new_length] = 0, *this;
    }

    _OSL_NODISCARD basic_string &operator+(const type object) {
        return this->operator+=(object), *this;
    }

    _OSL_NODISCARD basic_string &operator+(const type *pointer) {
        return this->operator+=(pointer), *this;
    }

    _OSL_NODISCARD basic_string &operator+(const basic_string &object) {
        return this->operator+=(object), *this;
    }

    _OSL_NODISCARD bool operator==(const type object) {
        if (_length > 1 || _length == 0) return false;
            return *this->_pointer == object;
    }

    _OSL_NODISCARD bool operator==(const type *pointer) {
        return string_compare(this->_pointer, const_cast<char*>(pointer));
    }

    _OSL_NODISCARD bool operator==(const basic_string &object) {
        return string_compare(this->_pointer, const_cast<char*>(object.c_str()));
    }

    _OSL_NODISCARD bool operator!=(const type object) {
        return !(*this == object);
    }

    _OSL_NODISCARD bool operator!=(const type *pointer) {
        return !(*this == pointer);
    }

    _OSL_NODISCARD bool operator!=(const basic_string &object) {
        return !(*this == object);
    }

    void clear() {
        _length = 0;
        this->free();
    }

    _OSL_NODISCARD const type *c_str() const _OSL_NOEXCEPT {
        return this->_pointer;
    }

    _OSL_NODISCARD u32 length() const _OSL_NOEXCEPT {
        return _length;
    }

protected:

    u32 _length;

};

OSL_END_NAMESPACE

#endif
