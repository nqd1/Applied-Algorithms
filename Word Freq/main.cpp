#include <bits/stdc++.h>
using namespace std;

string lowerCase(const string& str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}

int main() {
    map<string, int> wordFreq;
    string word;

    while (cin >> word) {
        word = lowerCase(word);
        wordFreq[word]++;
    }

     for(pair<string, int> words : wordFreq){
        cout << words.first << " " << words.second << endl;
    }
    return 0;
}
