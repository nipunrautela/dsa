#include<iostream>
#include<vector>
#include<cstdint>

std::vector<int32_t> applyPermutation(const std::vector<int32_t>& sequence, const std::vector<int32_t>& permutation) {
    std::vector<int32_t> newSequence(sequence.size());
    for(int32_t i=0; i<sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }

    return newSequence;
}

std::vector<int32_t> permute(std::vector<int32_t> sequence, std::vector<int32_t> permutation, int64_t k) {
    while(k > 0) {
        if (k % 2 == 1) {
            sequence = applyPermutation(sequence, permutation);
        }
        permutation = applyPermutation(permutation, permutation);
        k >>= 1;
    }

    return sequence;
}

void printVector(const std::vector<int32_t>& v) {
    for(int32_t x: v)
    std::cout << x << " ";
}

struct TestCase {
    std::vector<int32_t> sequence;
    std::vector<int32_t> permutation;
    int64_t operationCount;

    void printTestCaseData() {
        std::cout << "Original Sequence: ";
        printVector(sequence);
        std::cout << std::endl;

        std::cout << "Permutation: ";
        printVector(permutation);
        std::cout << std::endl;

        std::cout << "Operation Count: " << operationCount;
        std::cout << std::endl;
    }
};

int32_t main() {
    TestCase testCases[] = {
        {
            {53, 41, 12, 3, 74, 13},
            {5, 2, 1, 0, 4, 3},
            10
        },
        {
            {52, 31, 52, 12, 42, 13, 12},
            {0, 6, 5, 2, 1, 4, 3},
            53342
        },
        {
            {63, 84, 21, 3, 74, 13},
            {5, 3, 2, 1, 0, 4},
            425452
        }
    };

    for(TestCase t: testCases) {
        t.printTestCaseData();
        std::vector<int32_t> resSequence = permute(t.sequence, t.permutation, t.operationCount);
        std::cout << "Result: ";
        printVector(resSequence);
        std::cout << std::endl;
        std::cout << "###########################" << std::endl;
    }

    return 0;
}
