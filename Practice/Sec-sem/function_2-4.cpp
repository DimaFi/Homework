

#include <iostream>
using namespace std;

int count(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

void printNumber(int a) {
    int countA = count(a);
    int nextNumber = a + 1;
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
