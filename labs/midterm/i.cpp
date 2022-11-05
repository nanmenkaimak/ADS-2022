#include <bits/stdc++.h>

using namespace std;

vector<int> tobinary(long long num) {
    vector<int> v;
    int binary = 0, remainder, product = 1;
    while (num != 0) {
        remainder = num % 2;
        v.push_back(remainder);
        binary += (remainder * product);
        num = num / 2;
        product *= 10;
    }
    return v;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        long long x; cin >> x; 
        stack<long long> st;
        vector<int> v = tobinary(x);
        reverse(v.begin(), v.end());
        for(int j = 0; j < v.size(); j++) {
            if(st.empty()){
                st.push(v[j]);
            } else if(st.top() == 1 && v[j] == 0) {
                st.pop();
            } else st.push(v[j]);
        }
        if(st.empty()) cout <<"YES"<<endl;
        else cout << "NO" <<endl;
    }
}