#include <memory.hpp>
#include <allocator.hpp>

#ifndef _OSL_STRING_HPP
#define _OSL_STRING_HPP

namespace osl
{
    template <class _type>
    class basic_string : public osl::allocator<_type>
    {
    public:

        using type = _type;

        _OSL_CONSTEXPR basic_string() _OSL_NOEXCEPT { }

        basic_string(type const object) : _length(1) {
            this->allocate(2);
            this->_pointer[0] = object;
            this->_pointer[1] = 0;
        }

        basic_string(type const *pointer) : _length(string_length(pointer)) {
            this->allocate(_length + 1);
            memory_copy<type>(this->_pointer, pointer, _length);
            this->_pointer[_length] = 0;
        }

        basic_string(basic_string const &object) : _length(object.length()) {
            this->allocate(_length + 1);
            memory_copy<type>(this->_pointer, object.c_str(), _length);
            this->_pointer[_length] = 0;
        }

        basic_string &operator=(basic_string const &object) {
            _length = object.length();

            if (this->_allocated < _length + 1)
                this->reallocate(_length + 1);

            memory_copy<type>(this->_pointer, object.c_str(), _length);
            this->_pointer[_length] = 0;
            return *this;
        }

        basic_string &operator+=(basic_string const &object) {
            u64 length = object.length();
            u64 new_length = _length + length;

            if (this->_allocated < new_length + 1) {
                this->reallocate(new_length + 1);
            }

            memory_copy<type>(this->_pointer + _length, object.c_str(), length);
            this->_pointer[_length = new_length] = 0;
            return *this;
        }

        _OSL_NODISCARD type const *c_str() const _OSL_NOEXCEPT {
            return this->_pointer;
        }

        _OSL_NODISCARD u64 length() const _OSL_NOEXCEPT {
            return _length;
        }

        virtual ~basic_string() _OSL_NOEXCEPT { }

    protected:

        u64 _length;

    };
}

#endif