#pragma once

#include <stddef.h>

namespace osl
{
    template <class type>
    class safe_ptr
    {
    public:

        template <class... types>
        explicit safe_ptr(types&&... args) noexcept {
            _ptr = new type(args...);
        }

        safe_ptr(safe_ptr &object) noexcept {
            _ptr = object.release();
        }

        ~safe_ptr() noexcept {
            delete _ptr;
        }

        type *operator->() const noexcept {
            return _ptr;
        }

        type *operator*() const noexcept {
            return _ptr;
        }

        safe_ptr &operator=(safe_ptr& object) noexcept {
            _ptr = object.release();
            return *this;
        }

        type *get() const noexcept {
            return _ptr;
        }

        type *release() noexcept {
            type* buffer = _ptr;
            _ptr = nullptr;
            return buffer;
        }

    private:
        type *_ptr;
    };

    template <class type>
    class allocator
    {
    public:

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
            size_t _old_size = _allocated;
            type *_old_ptr = _pointer;
            _pointer = new type[size];
            memory_copy(_pointer, _old_ptr, _old_size);
            _allocated = size;
            delete _old_ptr;
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
