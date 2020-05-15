#pragma once

#include <cstddef>

namespace osl
{
    template <class type>
    class stack
    {

        struct node
        {
            type value;
            node *next;

            node(type value) : value(value) { }
        };

        node *head;

    public:

        using element_type = type;

        explicit stack() : head(0) { }

        void push(const type &value) {
            node *next = new node(value);
            next->next = head;
            head = next;
        }

        void pop() {
            node *buf = head->next;
            delete head;
            head = buf;
        }

        type top() const {
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
