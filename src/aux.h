#ifndef AUX_H
#define AUX_H

#include <memory>

#define CPP11 201103L

#if __cplusplus <= CPP11

namespace std {

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}
}

#endif

#endif // AUX_H
