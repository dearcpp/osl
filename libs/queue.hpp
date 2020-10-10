#include <inttypes.hpp>
#include <defines.hpp>

#ifndef _OSL_QUEUE_HPP
#define _OSL_QUEUE_HPP

namespace osl
{
    template <class _type>
    class queue
    {
    protected:

        struct node
        {
            _type value;
            node *next;

            node(_type value) : value(value) { }
        };

    public:

        using type = _type;

        _OSL_CONSTEXPR queue() _OSL_NOEXCEPT : _head(0) { }

        virtual ~queue() {
            clear();
        }

        void push(type const &value) {
            node *next = new node(value);
            next->next = _head;
            _head = next, _size++;
        }

        void pop() {
            node *buffer = _head->next;
            delete _head;
            _head = buffer, _size--;
        }

        _type top() const {
            return _head->value;
        }

        bool empty() const {
            return _head == 0;
        }

        u64 size() const {
            return _size;
        }

        void clear() {
            while (_head) {
                node *buffer = _head->next;
                delete _head;
                _head = buffer;
            }
        }

    protected:

        node *_head;
        u64 _size;

    };
}

#endif