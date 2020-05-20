#pragma once

#include <cstdlib>

namespace osl
{
    template <class type>
    void *memory_copy(type *destination, const type *source, size_t length) {
        while (length--)
            *destination++ = *source++;
        return destination;
    }

    template <class type>
    class safe_ptr
    {
    public:

        using element_type = type;

        template <class... types>
        explicit safe_ptr(types&&... args) {
            _ptr = new type(args...);
        }

        safe_ptr(safe_ptr &object) {
            _ptr = object.release();
        }

        ~safe_ptr() {
            delete _ptr;
        }

        type *operator->() const {
            return _ptr;
        }

        type *operator*() const {
            return _ptr;
        }

        safe_ptr &operator=(safe_ptr &object) {
            _ptr = object.release();
            return *this;
        }

        type *get() const {
            return _ptr;
        }

        type *release() {
            type *buffer = _ptr;
            _ptr = 0;
            return buffer;
        }

    private:

        type *_ptr;

    };

    template <class type>
    class allocator
    {
    public:

        using element_type = type;

        explicit allocator() : _allocated(0) { }

        allocator(size_t size) {
            allocate(size);
        }

        ~allocator() {
            delete _pointer;
        }

        size_t allocated() const {
            return _allocated;
        }

        void allocate(size_t size) {
            if (_allocated == 0) {
                _pointer = new type[_allocated = size];
            }
        }

        void reallocate(size_t size) {
            type *old_ptr = _pointer;
            _pointer = new type[size];
            memory_copy(_pointer, old_ptr, _allocated);
            _allocated = size;
            delete old_ptr;
        }

        void free() {
            delete _pointer;
            _allocated = 0;
        }

        type &operator[](size_t index) const {
            return _pointer[index];
        }

    private:

        type *_pointer;
        size_t _allocated;

    };
}
