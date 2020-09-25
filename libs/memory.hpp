#include <inttypes.hpp>
#include <defines.hpp>

#ifndef _OSL_MEMORY_HPP
#define _OSL_MEMORY_HPP

namespace osl
{
    template <class _type>
    void memory_copy(_type *destination, _type const *source, u64 length) {
        while (length--)
            *destination++ = *source++;
    }

    template <class _type>
    void memory_set(_type *destination, _type value, u64 length) {
        while (length--)
            *destination++ = value;
    }

    template <class _type>
    u64 string_length(_type *source) {
        u64 result = 0;
        while (*source++) result++;
        return result;
    }

    template <class _type>
    class safe_ptr
    {
    public:

        using type = _type;

        template <class... _types>
        safe_ptr(_types&&... args) {
            _pointer = new type(args...);
        }

        safe_ptr(safe_ptr &object) {
            _pointer = object.release();
        }

        virtual ~safe_ptr() {
            delete _pointer;
        }

        type *operator->() const {
            return _pointer;
        }

        type *operator*() const {
            return _pointer;
        }

        safe_ptr &operator=(safe_ptr &object) {
            _pointer = object.release();
            return *this;
        }

        _OSL_NODISCARD type *get() const {
            return _pointer;
        }

        _OSL_NODISCARD type *release() {
            type *buffer = _pointer;
            _pointer = 0;
            return buffer;
        }

    protected:

        type *_pointer;

    };
}

#endif