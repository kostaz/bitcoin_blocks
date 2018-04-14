#include <iostream>
#include <stdint.h>
#include <stdio.h>

// This program shows how to convert an array of uint8_t bytes to std::string.
// This is important in order to easily print an array of uint8_t members.

int main()
{
    static const char hexmap[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    uint8_t bytes[4] = {0xe7, 0xe8, 0xe9, 0xea};

    std::string s;
    for (int i = 0; i < 4; i++)
    {
        uint8_t byte = bytes[i];

        char byte_lsb = hexmap[byte & 0xf];
        char byte_msb = hexmap[byte >> 4];

        s.push_back(byte_msb);
        s.push_back(byte_lsb);
    }

    printf("0x%s\n", s.c_str());
    std::cout << "0x" << std::hex << s << std::endl;

    return 0;
}
