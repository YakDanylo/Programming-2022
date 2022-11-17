#include <iostream>
#include <string>

using namespace std;



int main()
{
    string t, words[10000];
    long long n;
    getline(cin, t);
    n = t.size();
    int flag = 0;
    int wordsnum = 1;
    for (int i = 0; i < n; i++) {
        if (t[i] == ' ' || t[i] == '.') {
            wordsnum++;
            flag = 0;
        }
        else {
            flag++;
            words[wordsnum].resize(flag);
            words[wordsnum][flag - 1] = t[i];
        }
    }
    for (int i = 1; i <= wordsnum; i++) {
        if (words[i].size() > i)
            cout << words[i] << endl;
    }

    return 0;
}