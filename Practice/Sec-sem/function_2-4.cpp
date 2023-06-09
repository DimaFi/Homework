

#include <iostream>
using namespace std;

int count(int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            count++;
        }
    }
    return count;
}

void printNumber(int A) {
    int countA = count(A);
    int nextNumber = A + 1;
    while (count(nextNumber) != countA) {
        nextNumber++;
    }

    cout << nextNumber << endl;
}

int main() {
    int number;

    cin >> number;

    printNumber(number);
}

// 12 -> 18
// 20 -> 28
