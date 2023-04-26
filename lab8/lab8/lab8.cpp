#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Compare {
    bool operator()(pair<string, int>& left, pair<string, int>& right) {
        if (left.second == right.second) {
            return left.first > right.first;
        }
        return left.second < right.second;
    }
};
bool x(char c, string s) {
    bool isTrue = false;
    for (int i = 0; i < s.length(); i++) {
        if (c == s.at(i)) {
            isTrue = true;
            break;
        } else
            isTrue = false;
    }
    return isTrue;
}
int main() {
    string myString;
    ifstream myFile("input.txt");
    if (!myFile) {
        cout << "Eroare la deschiderea fisierului: input.txt";
        return 0;
    }
    if (!getline(myFile, myString)) {
        cout << "Eroare la citirea din fisier: input.txt";
        return 0;
    }
    cout << "Sirul de caractere citit este: " << myString.c_str() << "\n";
    string phr;
    for (int i = 0; i < myString.length(); i++) {
        char c = tolower(myString[i]);
        phr.insert(phr.begin() + i, c);
    }
    vector<string> v;
    char delimit[] = " ,.?!";
    int l = 0;
    for (int i = 0; i < phr.length(); i++) {
        char c = phr.at(i);
        if (x(c, delimit)) {
            string sub = phr.substr(l, i - l);
            l = i + 1;
            if (sub.length() > 0) {
                v.push_back(sub);
            }
        }
    }

    map<string, int> mp;
    for (auto i = 0; i < v.size(); i++) {
        if (mp.count(v[i]) != 0)
            mp[v[i]]++;
        else
            mp[v[i]] = 1;
    }
    
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
    for (auto it = mp.begin(); it != mp.end(); it++)
        myQueue.push(pair<string,int>(it->first, it->second));
    while (!myQueue.empty()) {
        cout << myQueue.top().first << "=>" << myQueue.top().second << endl;
        myQueue.pop();
    }

return 0;
}