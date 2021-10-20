#ifndef _OSL_MEMORY_HPP_
#define _OSL_MEMORY_HPP_

# include <int_types.hpp>
# include <traits.hpp>
# include <assert.hpp>

OSL_BEGIN_NAMESPACE

template <class _Type>
void memory_copy(_Type *destination, const _Type *source, u32 length)
{
    if (!destination || !source || !length)
    {
        return;
    }

    using _NonConstType = OSL_REMOVE_CONST(_Type);
    _NonConstType *_destination = (_NonConstType*)destination, *_source = (_NonConstType*)source;

    while (length--) *_destination++ = *_source++;
}

template <class _Type>
void memory_set(_Type *destination, const _Type value, u32 length)
{
    if (!destination || !length)
    {
        return;
    }

    using _NonConstType = OSL_REMOVE_CONST(_Type);
    _NonConstType *_destination = (_NonConstType*)destination;

    while (length--) *_destination++ = value;
}

template <class _Type>
u32 string_length(_Type *source)
{
    if (!source)
    {
        return 0;
    }

    using _NonConstType = OSL_REMOVE_CONST(_Type);
    _NonConstType *_source = (_NonConstType*)source;

    u32 result = 0;
    while (*_source++) result++;

    return result;
}

template <class _Type>
bool string_compare(_Type *first, _Type *second)
{
    if (!first || !second)
    {
        return false;
    }

    using _NonConstType = OSL_REMOVE_CONST(_Type);
    _NonConstType *_first = (_NonConstType*)first, *_second = (_NonConstType*)second;

    do
    {
        if (*_first == 0 && *_second == 0) return true;
    }
    while (*_first++ == *_second++);

    return false;
}

template <class _Type>
class safe_ptr
{
public:

    using type = _Type;

    template <class... _Types>
    safe_ptr(_Types&&... args)
    {
        _pointer = new type(args...);
    }

    safe_ptr(safe_ptr &object)
    {
        _pointer = object.release();
    }

    virtual ~safe_ptr()
    {
        if (_pointer) delete _pointer;
    }

    type *operator->() const
    {
        return _pointer;
    }

    type *operator*() const
    {
        return _pointer;
    }

    safe_ptr &operator=(safe_ptr &object)
    {
        return _pointer = object.release(), *this;
    }

    _OSL_NODISCARD type *get() const
    {
        return _pointer;
    }

    _OSL_NODISCARD type *release()
    {
        type *buffer = _pointer;
        _pointer = 0;
        return buffer;
    }

protected:

    type *_pointer;

};

OSL_END_NAMESPACE

#endif
