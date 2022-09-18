#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<int> deq;

    char c;

    while(cin >> c) {
        if (c == '+') {
            int x; cin >> x;
            deq.push_front(x);
        } else if (c == '-') {
            int x; cin >> x;
            deq.push_back(x);
        } else if (c == '*') {
            if (deq.empty())
                cout <<"error"<<endl;
            else {
                cout << deq.front() + deq.back() <<endl;
                deq.pop_front();
                if(!deq.empty())
                    deq.pop_back();
            }
        } else if (c == '!') {
            return 0;
        }
    }
}