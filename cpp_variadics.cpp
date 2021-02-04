#include <cmath>

template<bool digit, bool... digits>
int reversed_binary_value(int i = 0)
{
    int out = digit ? (int)pow(2, i) : 0;
    return out + reversed_binary_value<digits...>(i + 1);
}

template<>
int reversed_binary_value<true>(int i)
{
    return (int)pow(2, i);
}

template<>
int reversed_binary_value<false>(int i)
{
    return 0;
}

