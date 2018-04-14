#include <iostream>
#include <stdint.h>
#include <stdio.h>

// This program shows how to convert a one uint8_t byte to std::string.
// This is important in order to easily print uint8_t variables,
// especially, arrays of uint8_t variables.

int main()
{
    static const char hexmap[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    uint8_t byte = 0xe7;
    char    byte_lsb = hexmap[byte & 0xf];
    char    byte_msb = hexmap[byte >> 4];

    std::string s;
    s.push_back(byte_msb);
    s.push_back(byte_lsb);

    printf("0x%s\n", s.c_str());
    std::cout << "0x" << std::hex << s << std::endl;

    return 0;
}
