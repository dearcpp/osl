#ifndef _OSL_ALLOCATOR_HPP_
#define _OSL_ALLOCATOR_HPP_

# include <memory.hpp>
# include <assert.hpp>

OSL_BEGIN_NAMESPACE

template <class _Type>
class allocator
{
public:

    using type = _Type;
    using size_type = u32;

    allocator() _OSL_NOEXCEPT : _ptr(0), _size(0) { }

    allocator(size_type size) : _ptr(0), _size(0)
    {
        allocate(size);
    }

    virtual ~allocator()
    {
        free();
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE size_type allocated() const _OSL_NOEXCEPT
    {
        return _size;
    }

    void allocate(size_type size)
    {
        if (_size != 0)
        {
            assert_failed(__FILE__, __LINE__, "impossible to re-allocate memory, use 'realloc' method");
        }
        _ptr = new _Type[_size = size];
    }

    void reallocate(size_type size)
    {
        if (size < _size) 
        {
            assert_failed(__FILE__, __LINE__, "impossible to re-allocate buffer for less memory count");
        }

        type *old_ptr = _ptr;
        _ptr = new type[size];

        if (old_ptr)
        {
            memory_copy(_ptr, old_ptr, _size);
            delete[] old_ptr;
        }

        _size = size;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE const type *data() const _OSL_NOEXCEPT
    {
        return _ptr;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE type *data() _OSL_NOEXCEPT
    {
        return _ptr;
    }

    _OSL_NODISCARD const type operator[](size_type index) const
    {
        if (index > _size - 1 || index < 0)
        {
            assert_failed(__FILE__, __LINE__, "out of bounds element getting");
        }
        return this->operator[](index);
    }

    _OSL_NODISCARD type &operator[](size_type index)
    {
        if (index > _size - 1 || index < 0)
        {
            assert_failed(__FILE__, __LINE__, "out of bounds element getting");
        }
        return _ptr[index];
    }

    void free()
    {
        delete[] _ptr;
        _ptr = 0;
        _size = 0;
    }

protected:

    type *_ptr;
    size_type _size;

};

OSL_END_NAMESPACE

#endif
