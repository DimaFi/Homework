#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main() {
    
    map<string, int> wordCountMap;
    vector<string> words;
    int lastNumber = 0;
    int number;

    string s;
    while (in >> s) {
        if (istringstream(s) >> number) {
            lastNumber = number;
        }
        else {
            wordCountMap[s]++;
            words.push_back(s);
        }
    }

    for (const string& word : words) {
        if (wordCountMap[word] == lastNumber) {
            cout << word << endl;
            out << word << endl;
        }
    }

    in.close();
    out.close();
}

// map 1 count map 2 stack stack 1 place
