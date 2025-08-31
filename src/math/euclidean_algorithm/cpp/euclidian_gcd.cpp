#include <iostream>

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

long long gcdIterative(long long a, long long b) {
    while(b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
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
        std::cout << "Result: " << gcdIterative(t.a, t.b) << std::endl;
        std::cout << "==========================" << std::endl;
    }

    return 0;
}
