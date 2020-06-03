#pragma once

#include <stddef.h>

namespace osl
{
    template <class _type>
    void *memory_copy(_type *destination, const _type *source, size_t length) {
        while (length--)
            *destination++ = *source++;
        return destination;
    }

    template <class _type>
    class safe_ptr
    {
    public:

        using element_type = _type;

        template <class... _types>
        explicit safe_ptr(_types&&... args) {
            _ptr = new _type(args...);
        }

        safe_ptr(safe_ptr &object) {
            _ptr = object.release();
        }

        ~safe_ptr() {
            delete _ptr;
        }

        _type *operator->() const {
            return _ptr;
        }

        _type *operator*() const {
            return _ptr;
        }

        safe_ptr &operator=(safe_ptr &object) {
            _ptr = object.release();
            return *this;
        }

        _type *get() const {
            return _ptr;
        }

        _type *release() {
            _type *buffer = _ptr;
            _ptr = 0;
            return buffer;
        }

    private:

        _type *_ptr;

    };
}