/**
 *
 */

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <mutex>
#include <condition_variable>
#include <memory>
#include <queue>

#include "message.h"

class MessageQueue {

public:
    template <typename M> void push(M const& msg) {
        std::lock_guard<std::mutex> lock(_mutex);
        _queue.push(std::make_shared<WrappedMessage<M> >(msg));
        _not_empty.notify_all();
    }

    std::shared_ptr<Message> wait_and_pop() {
        std::unique_lock<std::mutex> lock(_mutex);
        _not_empty.wait(lock, [&] {
            return !_queue.empty();
        });
        auto msg = _queue.front();
        _queue.pop();
        return msg;
    }

private:
    std::mutex _mutex;
    std::condition_variable _not_empty;
    std::queue<std::shared_ptr<Message> > _queue;

};

#endif