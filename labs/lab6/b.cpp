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

int main() {
    int n,m; cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<int> v;

    qsort(b, 0, m - 1);
    qsort(a, 0 , n - 1);

    int i = 0, j = 0;

    while(i < n && j < m) {
        if(a[i] == b[j]) {
            cout << a[i] << " ";
            i++; j++;
        } else if(a[i] > b[j]) {
            j++;
        } else i++;
    }

    // for(auto i : v) cout << i << " ";
}