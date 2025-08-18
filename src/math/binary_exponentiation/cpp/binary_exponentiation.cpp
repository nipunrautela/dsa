#include<iostream>

long long binPow(long long base, long long exp) {
    if (exp == 0)
        return 1;
    long long res = binPow(base, exp/2);
    if (exp % 2 == 1) 
        return res * res * base;
    else
        return res * res;
}

long long binPowIterative(long long base, long long exp) {
    long long res = 1;
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
    long long base;
    long long exp;

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
