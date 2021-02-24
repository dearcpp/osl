#ifndef _OSL_MEMORY_HPP
#define _OSL_MEMORY_HPP

# include <int_types.hpp>

OSL_BEGIN_NAMESPACE

template <class _type>
void memory_copy(_type *destination, const _type *source, u32 length) {
    while (length--)
        *destination++ = *source++;
}

template <class _type>
void memory_set(_type *destination, _type value, u32 length) {
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
bool string_compare(_type *first, _type *second) {
    do {
        if (*first == 0 && *second == 0) return true;
    } while (*first++ == *second++);
    return false;
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
        return _pointer = object.release(), *this;
    }

    _OSL_NODISCARD type *get() const {
        return _pointer;
    }

    _OSL_NODISCARD type *release() {
        type *buffer = _pointer;
        return _pointer = 0, buffer;
    }

protected:

    type *_pointer;

};

OSL_END_NAMESPACE

#endif
