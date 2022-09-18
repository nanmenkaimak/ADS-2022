#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> boris;
    vector<int> nursik;

    for(int i = 0; i < 5; i++) {
        int x; cin >> x;
        boris.push_back(x);
    }

    for(int i = 0; i < 5; i++) {
        int x; cin >> x;
        nursik.push_back(x);
    }

    int i = 0;
    while(!boris.empty() && !nursik.empty()) {
        i++;
        if (boris[0] == 0 && nursik[0] == 9) {
            boris.push_back(boris[0]);
            boris.push_back(nursik[0]);
            boris.erase(boris.begin());
            nursik.erase(nursik.begin());
        } else if (nursik[0] == 0 && boris[0] == 9) {
            nursik.push_back(boris[0]);
            nursik.push_back(nursik[0]);
            boris.erase(boris.begin());
            nursik.erase(nursik.begin());
        } else if (boris[0] > nursik[0]) {
            boris.push_back(boris[0]);
            boris.push_back(nursik[0]);
            boris.erase(boris.begin());
            nursik.erase(nursik.begin());
        } else if (boris[0] < nursik[0]) {
            nursik.push_back(boris[0]);
            nursik.push_back(nursik[0]);
            boris.erase(boris.begin());
            nursik.erase(nursik.begin());
        }
        if(boris.empty()) {
            cout << "Nursik " << i;
            return 0;
        } 
        if (nursik.empty()) {
            cout << "Boris " << i;
            return 0;
        } 
        if (i >= 1000000) {
            cout << "blin nichya";
            return 0;
        }
    }
}