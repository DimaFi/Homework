

#include <iostream>
#include <string>
#include <map>

using name space std;

int main() {
    string line;
    getline(cin, line);

    map<char, int> countMap;

    string word;
    string::size_type pos = 0;

    while (pos != string::npos) {
        pos = line.find_first_not_of(' ', pos);
        if (pos != string::npos) {
            char firstChar = std::tolower(line[pos]);
            countMap[firstChar]++;
            pos = line.find(' ', pos + 1); 
        }
    }

    char mostChar = ' ';
    int maxCount = 0;

    // Ищем букву с наибольшим количеством слов
    
    for (const auto& entry : countMap) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostChar = entry.first;
        }
    }

    cout « "Most char: " « mostChar « endl;
}
