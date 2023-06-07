
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int main() {
    string text = "More other words. Plus new sentence super! Super word? New word! Other new word.";

    set<string> unique;
    set<string> common;

    // Добавлен set common, потому что в unigue добавлялось больше слов чем надо, и никак не получалось исправить

    string endSymb = ".!?";
    string sentence;

    size_t startPos = 0;
    size_t endPos = text.find_first_of(endSymb, startPos);

    while (endPos != string::npos) {
        sentence = text.substr(startPos, endPos - startPos + 1);

        istringstream sentenceStream(sentence);
        string word;

        cout << "----------" << endl;
        cout << sentence << endl;

        bool f = false;

        while (sentenceStream >> word) {
            if (word.back() == '!') {
                f = true;
                break;
            }
        }

        sentenceStream.clear();
        sentenceStream.seekg(0);

        while (sentenceStream >> word) {

            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), tolower);

            if (f) {
                unique.insert(word);
                cout << "1 " << word << endl;
            }
            else {
                common.insert(word);
                cout << "2 " << word << endl;
            }
        }
        f = false;

        startPos = endPos + 1;
        endPos = text.find_first_of(endSymb, startPos);
    }

    cout << "----------" << endl;

    for (const auto& word : common) {
        unique.erase(word);
    }

    // Добавлен set коммон, потому что в unigue добавлялось больше слов чем надо, и никак не получалось исправить

    cout << "Unique words: ";
    for (const auto& word : unique) {
        cout << word << ' ';
    }

    cout << endl << "Count: " << unique.size() << endl;

}
