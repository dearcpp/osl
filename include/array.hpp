#ifndef _OSL_ARRAY_HPP_
#define _OSL_ARRAY_HPP_

# include <memory.hpp>
# include <initializer_list>

OSL_BEGIN_NAMESPACE

template <class _Type, u32 _Size>
class array
{
public:

    using type = _Type;
    using initializer_list = std::initializer_list<_Type>;

    _OSL_CONSTEXPR array() _OSL_NOEXCEPT { }

    array(initializer_list array) _OSL_NOEXCEPT
    {
        memory_copy(_storage, array.begin(), array.size());
    }

    _OSL_NODISCARD type operator[](u32 index) const
    {
        return _storage[index];
    }

    _OSL_NODISCARD type &operator[](u32 index)
    {
        return _storage[index];
    }

    _OSL_NODISCARD _OSL_CONSTEXPR u32 size() const
    {
        return _Size;
    }

protected:

    type _storage[_Size];

};

OSL_END_NAMESPACE

#endif
