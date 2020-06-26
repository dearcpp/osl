#pragma once

#include <cstddef>

namespace osl
{
    template <class _type>
    class queue
    {
    private:

        struct node
        {
            _type value;
            node *next;

            node(_type value) : value(value) { }
        };

        node *_head;

    public:

        using element_type = _type;

        queue() : _head(0) { }

        virtual ~queue() {
            clear();
        }

        void push(const _type &value) {
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

    };
}