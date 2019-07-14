#pragma once

#include <functional>
#include <vector>

class Util
{
public:
    Util();
    ~Util();
    template<typename T>
    std::vector<std::vector<std::reference_wrapper<T const>>> chunk(size_t, std::vector<T>) const;
private:
};

struct Set
{
    int i;
    float f;
    std::string s;
};

inline bool operator==(Set const& lhs, Set const& rhs)
{
    return lhs.i == rhs.i
        and lhs.f == rhs.f
        and lhs.s == rhs.s;
}