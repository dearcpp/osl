#pragma once

#include <memory.hpp>

namespace osl
{
    template <class _type>
    class allocator
    {
    public:

        using element_type = _type;

        allocator() :  _pointer(0), _allocated(0) { }

        allocator(size_t size) {
            allocate(size);
        }

        virtual ~allocator() {
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
            if (old_ptr) {
                memory_copy(_pointer, old_ptr, _allocated);
                delete old_ptr;
            }
            _allocated = size;
        }

        void free() {
            delete _pointer;
            _pointer = 0;
            _allocated = 0;
        }

        _type operator[](size_t index) const {
            return _pointer[index];
        }

        _type &operator[](size_t index) {
            return _pointer[index];
        }

    protected:

        _type *_pointer;
        size_t _allocated;

    };
}