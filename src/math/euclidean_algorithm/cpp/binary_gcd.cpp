#include <iostream>

long long binaryGcd(long long a, long long b) {
    if (a==0 || b==0)
        return a | b;

    unsigned long long shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            std::swap(a, b);
        }
        b = b - a;
    } while(b != 0);

    return a << shift;
}

struct TestCase {
    long long a;
    long long b;

    void print() {
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
    }
};

int main() {
    TestCase testCases[] = {
        {6, 4},
        {18, 12},
        {1'243'541, 64'241'624'331},
        {28'542'785, 43'930'600'526},
        {14'366'557'537'464'350, 6'425'327'453'425'412}
    };

    for(TestCase t: testCases) {
        t.print();
        std::cout << "Result: " << binaryGcd(t.a, t.b) << std::endl;
        std::cout << "==========================" << std::endl;
    }

    return 0;
}

