#include <bits/stdc++.h>

using namespace std;

int partition(int * a, int low, int high) {
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++) {
        if(a[j] < a[pivot]) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);
    return i + 1;
}

void qsort(int * a, int low, int high) {
    if(low < high) {
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

void ans(int * a, int n) {
    int mindiff = INT_MAX;
    for(int i = 1; i < n; i++) {
        mindiff = min(mindiff, abs(a[i] - a[i-1]));
    }
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i - 1] == mindiff) 
            cout << a[i - 1] << " " << a[i] <<" ";
    }
} 

int main() {

    int n; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    qsort(a, 0, n - 1);
    ans(a,n);
}