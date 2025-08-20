#include<iostream>
#include<cstdint>

int64_t multiplyViaBinExp(int64_t num1, int64_t num2, int64_t mod) {
    if (num1 == 0) return 0;
    if (num1 % 2 == 0) {
        return 2ll * multiplyViaBinExp(num1/2, num2, mod) % mod;
    }
    else {
        return 2ll * ((multiplyViaBinExp((num1-1)/2, num2, mod) % mod) + (num2 % mod)) % mod;
    }
}

struct TestCase {
    int64_t a;
    int64_t b;

    void print() {
        std::cout << "Num 1: " << a << std::endl;
        std::cout << "Num 2: " << b << std::endl;
    }
};

int main() {
    constexpr int64_t MOD = 1e9 + 7;
    TestCase testCases[] = {
        {31463131443, 3415315315},
        {421414124214, 1253613434},
        {53531535, 531515151515}
    };

    for(TestCase& t: testCases) {
        t.print();
        std::cout << "Result: " << multiplyViaBinExp(t.a, t.b, MOD) << std::endl;
        std::cout << "###############################" << std::endl;
    }

    return 0;
}
