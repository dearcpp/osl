#ifndef _OSL_ALLOCATOR_HPP
#define _OSL_ALLOCATOR_HPP

# include <memory.hpp>
# include <assert.hpp>

OSL_BEGIN_NAMESPACE

template <class _type>
class allocator
{
public:

    using type = _type;

    _OSL_CONSTEXPR allocator() _OSL_NOEXCEPT : _pointer(0), _allocated(0) { }

    allocator(u32 size) : _pointer(0), _allocated(0) {
        allocate(size);
    }

    virtual ~allocator() {
        free();
    }

    u64 allocated() const {
        return _allocated;
    }

    void allocate(u32 size) {
        if (_allocated == 0) {
            _pointer = new _type[_allocated = size];
        } else assert_failed(__FILE__, __LINE__, "impossible to re-allocate memory, use 'realloc' method");
    }

    virtual void reallocate(u32 size) {
        if (size >= _allocated) {
            type *old_ptr = _pointer;
            _pointer = new type[size];
            if (old_ptr) {
                memory_copy(_pointer, old_ptr, _allocated);
                delete[] old_ptr;
            }
            _allocated = size;
        } else assert_failed(__FILE__, __LINE__, "impossible to re-allocate buffer for less memory count");
    }

    _OSL_NODISCARD const type *data() const _OSL_NOEXCEPT {
        return _pointer;
    }

    _OSL_NODISCARD type *data() _OSL_NOEXCEPT {
        return _pointer;
    }

    _OSL_NODISCARD type operator[](u32 index) const {
        return _pointer[index];
    }

    _OSL_NODISCARD type &operator[](u32 index) {
        return _pointer[index];
    }

    void free() {
        delete[] _pointer;
        _pointer = 0;
        _allocated = 0;
    }

protected:

    type *_pointer;
    u32 _allocated;

};

OSL_END_NAMESPACE

#endif
