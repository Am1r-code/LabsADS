#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;
    cin.ignore(); 
    for (int t = 0; t < T; ++t) {
        string line;
        getline(cin, line);
        vector<string> words;
        string word;
        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);
        stable_sort(words.begin(), words.end(),
                    [](const string &a, const string &b) {
                        return a.size() < b.size();
                    });
        for (size_t i = 0; i < words.size(); ++i) {
            cout << words[i];
            if (i + 1 < words.size()) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
