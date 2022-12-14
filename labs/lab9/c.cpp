#include <bits/stdc++.h>

using namespace std;

vector<size_t> f(string str) {
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i++) {
        size_t j = v[i - 1];
        while(j > 0 && str[j] != str[i]) {
            j = v[j - 1];
        }
        if(str[i] == str[j]) {
            v[i] = j + 1;
        }
    }
    return v;
}

int main() {
    string word1, word2; cin >> word1 >> word2;
    int cnt = 0;
    string str = word2 + '#' + word1 + word1;
    vector<size_t> v = f(str);
    // for(auto i : v) cout << i <<" ";
    // cout <<endl;
    for(int i = word2.size() + 1; i < v.size(); i++){
        if(v[i] == word2.size()){
            cout << v[str.size() - 1];
            return 0;
        }
    }
    cout << -1;
}