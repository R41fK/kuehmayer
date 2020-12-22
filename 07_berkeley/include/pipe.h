#ifndef PIPE_H
#define PIPE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class Pipe {
    std::queue<T> backend;
    std::mutex mtx;
    std::condition_variable not_empty;
    bool closed{false};
  public:
    Pipe& operator<<(T value) {
        std::lock_guard lg{mtx};
        if (closed) {
            return *this;
        }
        backend.push(value);
        not_empty.notify_one();
        return *this;
    }
    
    Pipe& operator>>(T& value) {
        std::unique_lock ul{mtx};
        if (closed) {
            return *this;
        }
        not_empty.wait(ul, [this](){return this->backend.size() > 0;});
        value = backend.front();
        backend.pop();
        return *this;
    }

    void close() {
        closed = true;
    }
    
    explicit operator bool() {
        return !closed;
    }
};
#endif
