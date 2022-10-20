#include <bits/stdc++.h>

using namespace std;


void merge(string * a, int l, int m, int r){
    int i1 = m - l + 1;
    int i2 = r - m;
    string L[i1], R[i2];

    for(int k = 0; k < i1; k++) {
        L[k] = a[l + k];
    }
    for(int k = 0; k < i2; k++) {
        R[k] = a[m + 1 + k];
    }
    int j = 0, i = 0, k = l;

    while(i < i1 && j < i2){
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < i1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < i2) {
        a[k] = R[j];
        j++;
        k++;
    }

}

void msort(string * a, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n; cin >> n;
    
}