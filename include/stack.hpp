#pragma once

#include <stddef.h>

namespace osl
{
    template <class _type>
    class stack
    {

        struct node
        {
            _type value;
            node *next;

            node(_type value) : value(value) { }
        };

        node *head;

    public:

        using element_type = _type;

        explicit stack() : head(0) { }

        void push(const _type &value) {
            node *next = new node(value);
            next->next = head;
            head = next;
        }

        void pop() {
            node *buf = head->next;
            delete head;
            head = buf;
        }

        _type top() const {
            return head->value;
        }

        bool empty() const {
            return head == 0;
        }

        size_t size() const {
            size_t counter = 0;
            node *curr = head;
            while (curr) {
                counter++;
                curr = curr->next;
            }
            return counter;
        }

        void clear() {
            while (head) {
                node *buf = head->next;
                delete head;
                head = buf;
            }
        }

    };
}