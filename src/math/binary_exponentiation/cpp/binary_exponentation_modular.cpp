#include<iostream>

long long binPowModular(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;

    while(exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
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
    constexpr long long MOD = 1e9 + 7;
    TestCase testCases[] = {
        {1021, 16},
        {1224, 92},
        {6423, 83},
        {31145, 52},
        {3321, 12}
    };

    for(TestCase& t: testCases) {
        t.print();
        std::cout << "Result: " << binPowModular(t.base, t.exp, MOD) << std::endl;
        std::cout << "#################" << std::endl;
    }

    return 0;
}
