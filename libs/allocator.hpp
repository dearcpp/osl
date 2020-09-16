#include <memory.hpp>
#include <defines.hpp>

#ifndef _OSL_ALLOCATOR_HPP
#define _OSL_ALLOCATOR_HPP

namespace osl
{
    template <class _type>
    class allocator
    {
    public:

        using type = _type;

        _OSL_CONSTEXPR allocator() _OSL_NOEXCEPT : _pointer(0), _allocated(0) { };

        allocator(u64 size) {
            allocate(size);
        }

        virtual ~allocator() {
            free();
        }

        u64 allocated() const {
            return _allocated;
        }

        void allocate(u64 size) {
            if (_allocated == 0) {
                _pointer = new _type[_allocated = size];
            }
        }

        void reallocate(u64 size) {
            type *old_ptr = _pointer;
            _pointer = new type[size];
            if (old_ptr) {
                memory_copy(_pointer, old_ptr, _allocated);
                delete old_ptr;
            }
            _allocated = size;
        }

        _OSL_NODISCARD type *data() _OSL_NOEXCEPT {
            return _pointer;
        }

        _OSL_NODISCARD type operator[](u64 index) const {
            return _pointer[index];
        }

        _OSL_NODISCARD type &operator[](u64 index) {
            return _pointer[index];
        }

        void free() {
            delete _pointer;
            _pointer = 0;
            _allocated = 0;
        }

    protected:

        type *_pointer;
        u64 _allocated;

    };
}

#endif