#include <bits/stdc++.h>

using namespace std;

int partition(char * a, int low, int high) {
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++) {
        if(a[j] < a[pivot]) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void qsort(char * a, int low, int high) {
    if(low < high) {
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main() {
    int n; cin >> n;
    char b[n];
    char a[n];
    vector<char> vowel;
    vector<char> other;
    int j = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u'){
            a[j] = b[i];
            j++;
        } else other.push_back(b[i]);
    }
    int k = 0;
    for(int i = j; i < n; i++){
        a[i] = other[k];
        k++;
    }
    qsort(a, 0, j - 1);
    qsort(a, j, n - 1);

    for(int i = 0; i < n; i++) cout << a[i];
}