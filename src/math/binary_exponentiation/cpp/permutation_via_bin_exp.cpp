#include<iostream>
#include<vector>

std::vector<int> applyPermutation(const std::vector<int>& sequence, const std::vector<int>& permutation) {
    std::vector<int> newSequence(sequence.size());
    for(int i=0; i<sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }

    return newSequence;
}

std::vector<int> permute(std::vector<int> sequence, std::vector<int> permutation, long long k) {
    while(k > 0) {
        if (k % 2 == 1) {
            sequence = applyPermutation(sequence, permutation);
        }
        permutation = applyPermutation(permutation, permutation);
        k >>= 1;
    }

    return sequence;
}

void printVector(const std::vector<int>& v) {
    for(int x: v)
    std::cout << x << " ";
}

struct TestCase {
    std::vector<int> sequence;
    std::vector<int> permutation;
    long long operationCount;

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

int main() {
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
        std::vector<int> resSequence = permute(t.sequence, t.permutation, t.operationCount);
        std::cout << "Result: ";
        printVector(resSequence);
        std::cout << std::endl;
        std::cout << "###########################" << std::endl;
    }

    return 0;
}
