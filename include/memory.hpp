#pragma once

namespace osl
{
    template <class type>
    class safe_ptr
    {
    public:

        template <class... types>
        explicit safe_ptr(types&&... args) noexcept {
            _ptr = new type(args...);
        }

        safe_ptr(safe_ptr &object) noexcept {
            _ptr = object.release();
        }

        ~safe_ptr() noexcept {
            delete _ptr;
        }

        type *operator->() const noexcept {
            return _ptr;
        }

        type *operator*() const noexcept {
            return _ptr;
        }

        safe_ptr &operator=(safe_ptr& object) noexcept {
            _ptr = object.release();
            return *this;
        }

        type *get() const noexcept {
            return _ptr;
        }

        type *release() noexcept {
            type* buffer = _ptr;
            _ptr = nullptr;
            return buffer;
        }

    private:
        type *_ptr;
    };
}
