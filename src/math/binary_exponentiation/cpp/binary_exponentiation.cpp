#include<iostream>
#include<cstdint>

int64_t binPow(int64_t base, int64_t exp) {
    if (exp == 0)
        return 1;
    int64_t res = binPow(base, exp/2);
    if (exp % 2 == 1) 
        return res * res * base;
    else
        return res * res;
}

int64_t binPowIterative(int64_t base, int64_t exp) {
    int64_t res = 1;
    while(exp != 0) {
        if (exp % 2 == 1) {
            res *= base;
        }
        base = base * base;
        exp >>= 1; // equivalent to exp = exp / 2;
    }

    return res;
}

struct TestCase {
    int64_t base;
    int64_t exp;

    void print() {
        std::cout << "Base: " << base << std::endl;
        std::cout << "Power: " << exp << std::endl;
    }
};

int main() {
    TestCase testCases[] = {
        {10, 6},
        {124, 9},
        {64, 8},
        {3145, 5},
        {31, 12}
    };

    for(TestCase& t: testCases) {
        t.print();
        std::cout << "Result: " << binPowIterative(t.base, t.exp) << std::endl;
        std::cout << "#################" << std::endl;
    }

    return 0;
}
