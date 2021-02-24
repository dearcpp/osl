#ifndef _OSL_VECTOR_HPP
#define _OSL_VECTOR_HPP

# include <defines.hpp>
# include <allocator.hpp>
# include <int_types.hpp>

# include <initializer_list>

OSL_BEGIN_NAMESPACE

template <class _type>
class vector_allocator : public allocator<_type>
{
public:

    using type = _type;

    using allocator<_type>::allocator;

    virtual ~vector_allocator() { }

    virtual void sized_reallocate(u32 size, u32 destination_offset = 0, u32 source_offset = 0, u32 length = 0) {
        type *old_ptr = this->_pointer;
        this->_pointer = new type[size];
        if (old_ptr) {
            memory_copy(this->_pointer + destination_offset, old_ptr + source_offset, length);
            delete[] old_ptr;
        }
        this->_allocated = size;
    }

};

template <class _type, class _allocator = vector_allocator<_type>>
class vector : public _allocator
{
public:

    using type = _type;

    vector(std::initializer_list<_type> list) : _allocator(list.size()), _length(list.size()) {
        for (u32 i = 0; i < _length; ++i) {
            this->operator[](i) = list.begin()[i];
        }
    }

    virtual ~vector() { }

    void push_front(const type &value) {
        if (this->allocated() < ++_length)
            this->sized_reallocate(_length, 1, 0, this->_length - 1);

        this->operator[](0) = value;
    }

    void push_back(const type &value) {
        _length++;

        if (this->allocated() < _length)
            this->reallocate(_length);

        this->operator[](_length - 1) = value;
    }

    void pop_front() {
        _length--, this->sized_reallocate(_length, 0, 1, _length);
    }

    void pop_back() {
        _length--, this->sized_reallocate(_length, 0, 0, _length);
    }

    _OSL_NODISCARD u32 length() const _OSL_NOEXCEPT {
        return _length;
    }

protected:

    u32 _length;

};

OSL_END_NAMESPACE

#endif
