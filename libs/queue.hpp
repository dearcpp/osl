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
            _head = next;
        }

        void pop() {
            node *buf = _head->next;
            delete _head;
            _head = buf;
        }

        _type top() const {
            return _head->value;
        }

        bool empty() const {
            return _head == 0;
        }

        size_t size() const {
            size_t counter = 0;
            node *curr = _head;
            while (curr) {
                counter++;
                curr = curr->next;
            }
            return counter;
        }

        void clear() {
            while (_head) {
                node *buf = _head->next;
                delete _head;
                _head = buf;
            }
        }

    protected:

        node *_head;

    };
}

#endif