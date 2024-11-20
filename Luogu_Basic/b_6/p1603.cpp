#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitStringIntoWords(const string &str) {
  vector<string> words;
  string word;
  for (char ch : str) {
    if (ch == ' ') {
      if (!word.empty()) {
        words.push_back(word);
        word.clear();
      }
    } else {
      word.push_back(ch);
    }
  }
  if (!word.empty()) {
    words.push_back(word);
  }
  return words;
}

int main() {
  string input;
  getline(cin, input);

  vector<string> words = splitStringIntoWords(input);

  vector<string> numbers;

  for (int i = 0; i < 6; i++) {
    int curr = 0;
    if (words[i] == "one")
      curr = 1;
    else if (words[i] == "two")
      curr = 2;
    else if (words[i] == "three")
      curr = 3;
    else if (words[i] == "four")
      curr = 4;
    else if (words[i] == "five")
      curr = 5;
    else if (words[i] == "six")
      curr = 6;
    else if (words[i] == "seven")
      curr = 7;
    else if (words[i] == "eight")
      curr = 8;
    else if (words[i] == "nine")
      curr = 9;
    else if (words[i] == "ten")
      curr = 10;
    else if (words[i] == "eleven")
      curr = 11;
    else if (words[i] == "twelve")
      curr = 12;
    else if (words[i] == "thirteen")
      curr = 13;
    else if (words[i] == "fourteen")
      curr = 14;
    else if (words[i] == "fifteen")
      curr = 15;
    else if (words[i] == "sixteen")
      curr = 16;
    else if (words[i] == "seventeen")
      curr = 17;
    else if (words[i] == "eighteen")
      curr = 18;
    else if (words[i] == "nineteen")
      curr = 19;
    else if (words[i] == "twenty")
      curr = 20;
    else if (words[i] == "a")
      curr = 1;
    else if (words[i] == "both")
      curr = 2;
    else if (words[i] == "another")
      curr = 1;
    else if (words[i] == "first")
      curr = 1;
    else if (words[i] == "second")
      curr = 2;
    else if (words[i] == "third")
      curr = 3;

    if (curr != 0) {
      int currnum = (curr * curr) % 100;
      string temp = "";
      (currnum > 10) ? numbers.push_back(to_string(currnum))
                     : numbers.push_back(("0" + to_string(currnum)));
      temp.clear();
    }
  }
  sort(numbers.begin(), numbers.end());

  string output = "";

  for (string a : numbers) {
    output.append(a);
  }
  while (output[0] == '0') {
    output = output.substr(1);
  }
  if (output.length() == 0)
    output = "0";
  cout << output << endl;
}