#include <iostream>
#include <vector>
#include <stdint.h>

/**
 * Convert iteratable sequence of uint8_t in reverse order.
 */
template<typename T>
std::string HexStr(const T& itbegin, const T& itend, bool fSpaces=false)
{
    std::string rv;

    static const char hexmap[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    rv.reserve((itend-itbegin)*3);

    for (T it = itbegin; it != itend; it++)
    {
        uint8_t val = (uint8_t)(*it);

        if (it != itbegin && fSpaces)
            rv.push_back(' ');

        rv.push_back(hexmap[val>>4]);
        rv.push_back(hexmap[val&15]);
    }

    return rv;
}

/**
 * Convert vector to string in reverse order.
 */
template<typename T>
inline std::string HexStr(const T& vch, bool fSpaces=false)
{
    return HexStr(vch.rbegin(), vch.rend(), fSpaces);
}

int main()
{
    std::string rev_str;

    /***********************************************************
     * Convert array of uint8_t to std::string in reverse order.
     */
    uint8_t data[] = {0xaf, 0xb7, 0x4f, 0x56};

    rev_str = HexStr(std::reverse_iterator<uint8_t*>(data + sizeof(data)),
                     std::reverse_iterator<uint8_t*>(data));

    std::cout << rev_str << std::endl;

    /***********************************************************
     * Convert std::vector of uint8_t to std::string in reverse order.
     */
    std::vector<uint8_t> v = {0xaf, 0xb7, 0x4f, 0x56}; // C++11 or above

    rev_str = HexStr(v);

    std::cout << rev_str << std::endl;

    return 0;
}
