#ifndef SAOD_COUNTER
#define SAOD_COUNTER

#include "./bitset.cpp"
#define SIZE 1024*1024


namespace saod 
{


class counter {

    private:
        bitset row;                  // array of bits
                                     // unused first bit is CARRY variable
        unsigned int len;            // length of representation
        uint8_t last_digit;          // the last (least-significant) digit of representation (x)
        unsigned int two_index;      // index of digit with value 2 (alpha)
        unsigned int prev_two_i;     // previous value of two_index (beta)
        unsigned int zero_counter;   // sigma

        void initialize();
        void increment();
        void decrement();
        void fix_carry();
        void fix_borrow();

    public:
        counter();

        void print_raw();
        void print_num();
        operator int() const;
        counter& operator ++ ();
        counter& operator ++ (int);
        counter& operator -- ();

};


counter::counter()
{
    row.realloc(SIZE);
    initialize();
}


void counter::initialize()
{
    len = 1;
    last_digit = 0;
    two_index = prev_two_i = 1;
    zero_counter = 0;
}


void counter::increment()
{
    if (two_index == prev_two_i) {   // work in normal mode
        fix_carry();
        prev_two_i = two_index;
    }
    else                             // work in search mode
        prev_two_i += 2;

    last_digit++;
}


void counter::fix_carry()
{
    bool carry = row.get(0) == 1;

    if (carry) {
        row.reset(two_index);
        zero_counter++;
        two_index++;
    }
    else if (last_digit >= 2) {
        last_digit -= 2;
        two_index = 1;
    }
    else return;

    if (two_index == len) {
        len++;
        row.set(len - 1);
        row.reset(0); // carry = 0;
    } 
    else if (row.get(two_index) == 0) {
        row.set(two_index);
        zero_counter--;
        row.reset(0); // carry = 0;
    }
    else 
        row.set(0); // carry = 1;
}


void counter::decrement()
{
    if (len == 1 || (last_digit == 2 && zero_counter == 0)) {
        last_digit--;
        return;
    }

    if (row.get(prev_two_i) != 0) { // work in normal mode
        fix_borrow();
        prev_two_i = two_index;
    }
    else if (row.get(two_index) == 0) { // work in search mode
        two_index++;
        if (row.get(two_index) == 0)
            two_index++;
        else     // swich to rapid mode
            fix_borrow();
    }
    else { // work in rapid mode
        fix_borrow();
        fix_borrow();
    }

    last_digit--;
}


void counter::fix_borrow()
{
    bool carry = row.get(0) == 1;
    // unsigned int gamma = two_index; // ???

    if (carry)
        row.set(two_index);
    else if (two_index == len - 1)
        len--;
    else {
        row.reset(two_index);
        zero_counter++;
    }

    if (two_index > 1) {
        two_index--;
        row.set(two_index);
        row.set(0); // carry = 1;
        zero_counter--;
    }
    else {
        last_digit += 2;
        row.reset(0); // carry = 0;
    }

}


void counter::print_raw()
{
    bool carry = row.get(0) == 1;

    std::cout << "REP = ";
    for (int d, i = len-1; i > 0; i--)
    {
        d = row.get(i);
        if (carry && i == two_index)
            std::cout << 2;
        else
            std::cout << (int) d;
    }
    std::cout << (int) last_digit << std::endl;
}


void counter::print_num()
{
    std::cout << "VAL = " << (int) *this << std::endl;
}



counter::operator int() const
{
    bool carry = row.get(0) == 1;
    unsigned long long factor = 2;
    unsigned long long res = last_digit;

    for (int i = 1; i < len; i++)
    {
        res += factor * row.get(i);
        if (carry && i == two_index)
            res += factor;
    
        factor *= 2;
    }

    //!!! implicit type conflict
    return res;
}


counter& counter::operator ++ ()
{
    increment();
}

counter& counter::operator ++ (int)
{
    increment();
}

counter& counter::operator -- ()
{
    decrement();
}




} // namespace saod

#endif // SAOD_COUNTER