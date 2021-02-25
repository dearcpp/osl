#ifndef _OSL_QUEUE_HPP
#define _OSL_QUEUE_HPP

# include <int_types.hpp>
# include <assert.hpp>

OSL_BEGIN_NAMESPACE

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

    _OSL_CONSTEXPR queue() _OSL_NOEXCEPT : _head(0), _size(0) { }

    queue(const queue &queue) _OSL_NOEXCEPT : _head(0), _size(0) {
        for (auto it = queue._head; it != 0; it = it->next) {
            this->push(it->value);
        }
    }

    virtual ~queue() {
        clear();
    }

    void push(const type &value) {
        node *next = new node(value);
        next->next = _head;
        _head = next, _size++;
    }

    void pop() {
        if (_size == 0)
            assert_failed(__FILE__, __LINE__, "failed to pop element from queue");

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
        auto it = _head;
        while (it != 0) {
            node *buffer = it->next;
            delete it;
            it = buffer;
        }
        _head = 0, _size = 0;
    }

protected:

    node *_head;
    u64 _size;

};

OSL_END_NAMESPACE

#endif
