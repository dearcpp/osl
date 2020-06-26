#pragma once

#include <stddef.h>

namespace osl
{
    template <class _type, size_t _size>
    class array
    {
    public:

        using element_type = _type;

        _type operator[](size_t index) const {
            return _storage[index];
        }

        _type &operator[](size_t index) {
            return _storage[index];
        }

        constexpr size_t size() const {
            return _size;
        }

    private:

        _type _storage[_size];

    };
}