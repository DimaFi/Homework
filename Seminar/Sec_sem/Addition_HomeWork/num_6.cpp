

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> to_vec(const string& str) {
  vector<string> words;
  istringstream iss(str);
  string word;

  while (iss >> word) {
    words.push_back(word);
  }

  return words;
}

void f(vector<string>& vec1, vector<string>& vec2, vector<string>& intersection, vector<string>& difference) {
  for (auto& word : vec1) {
    string lowerWord = word;
    transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
    if (find(vec2.begin(), vec2.end(), lowerWord) != vec2.end()) 
      intersection.push_back(word);
    else 
      difference.push_back(word);
  }

  for (auto& word : vec2) {
    string lowerWord = word;
    transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    if (find(vec1.begin(), vec1.end(), lowerWord) == vec1.end()) 
      difference.push_back(word);
  }
}

int main() {
  string str1 = "Hello world! This is a test.";
  string str2 = "Hello there! This is another test.";

  vector<string> words1 = to_vec(str1);
  vector<string> words2 = to_vec(str2);

  vector<string> intersection;
  vector<string> difference;

  f(words1, words2, intersection, difference);

  cout<< "Intersection: ";
  for (const auto& word : intersection) {
    cout << word << ' ';
  }
  cout <<endl;

  cout << "Difference: ";
  for (const auto& word : difference) {
    cout <<word << ' ';
  }
  cout << endl;
}
