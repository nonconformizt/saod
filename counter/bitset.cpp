#ifndef SAOD_BITSET
#define SAOD_BITSET
#include <iostream>

namespace saod
{



class bitset {

    private:
        uint8_t * array;
        unsigned int bits_n;
        unsigned int bytes_n;


    public:
        bitset() {};
        bitset(unsigned int);
        uint8_t get(unsigned int) const;
        void set(unsigned int);
        void reset(unsigned int);
        void realloc(unsigned int);

        friend std::ostream & operator << (std::ostream &out, const bitset & set);
        uint8_t operator [] (int i) const; // only getter, not setter

};



bitset::bitset (unsigned int n)
{
    bits_n = n;
    bytes_n = (bits_n + 8 - 1) / 8; // integer ceiling
    
    array = new uint8_t[bytes_n];
}


uint8_t bitset::get(unsigned int n) const
{
    return (array[n / 8] & ( 1 << (n % 8) )) >> (n % 8);
}


void bitset::set(unsigned int n)
{
    array[n / 8] |= (1U << (n % 8));
}


void bitset::reset(unsigned int n)
{
    array[n / 8] &= ~(1U << (n % 8));
}


void bitset::realloc(unsigned int n)
{
    bits_n = n;
    bytes_n = (bits_n + 8 - 1) / 8;
    // delete[] array;
    array = new uint8_t[bytes_n];
}


std::ostream & operator << (std::ostream &out, const bitset & set)
{
    for (int i = 0; i < set.bytes_n; i++ )
        for (int k = 0; k < 8; k++)
            out << ((set.array[i] & ( 1 << k )) >> k);

    out << std::endl;

    return out;
}


uint8_t bitset::operator [] (int i) const
{
    return get(i);
}




} // namespace saod

#endif