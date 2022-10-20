#include <bits/stdc++.h>

using namespace std;

struct Date{
    int day, month, year;
};

bool comp(Date &a, Date &b) {
    if(a.year < b.year) 
        return true;
    if(a.year == b.year && a.month < b.month)
        return true;
    if(a.year == b.year && a.month == b.month && a.day < b.day)
        return true;
    return false;
}

int main() {
    int n; cin >> n;
    vector<Date> v;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int day = stoi(s.substr(0,2));
        int month = stoi(s.substr(3,4));
        int year = stoi(s.substr(6,9));
        v.push_back({day, month, year});
    }

    sort(v.begin(), v.end(), comp);

    for(auto i : v) {
        if(i.day < 10) 
            cout << "0" << i.day;
        else cout << i.day;
        if(i.month < 10) 
            cout << "-0" <<i.month;
        else cout << "-" <<i.month; 
        cout << "-" << i.year <<endl;
    }
}