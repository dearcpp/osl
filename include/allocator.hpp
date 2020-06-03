#pragma once

#include <memory.hpp>

namespace osl
{
    template <class _type>
    class allocator
    {
    public:

        using element_type = _type;

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
                _pointer = new _type[_allocated = size];
            }
        }

        void reallocate(size_t size) {
            _type *old_ptr = _pointer;
            _pointer = new _type[size];
            memory_copy(_pointer, old_ptr, _allocated);
            _allocated = size;
            delete old_ptr;
        }

        void free() {
            delete _pointer;
            _allocated = 0;
        }

        _type operator[](size_t index) const {
            return _pointer[index];
        }

        _type &operator[](size_t index) {
            return _pointer[index];
        }

    private:

        _type *_pointer;
        size_t _allocated;

    };
}