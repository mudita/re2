#ifndef __NOTHR_H__
#define __NOTHR_H__

#include <functional>
#include <utility>

namespace re2 {

using once_flag = bool;

template <typename Callable, typename... Args>
void call_once(once_flag& flag, Callable&& f, Args&&... args ) {
    if (flag) {
        return;
    }

    flag = true;
    std::invoke(std::forward<Callable>(f), std::forward<Args>(args) ...);
}

class dummy_mutex {
    public:
        dummy_mutex() = default;
        void lock() {};
        void unlock() {};
};

}

#endif // __NOTHR_H__
