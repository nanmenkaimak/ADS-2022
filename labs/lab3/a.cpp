#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int x,y; cin >> x >> y;
    int a[x][y];

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }

    int i = 0, j = y - 1;
    for(int k = 0; k < n; k++) {
        while(i != x && j != y && j >= 0 && i >= 0) {
            // cout << i << " " << j << " " << a[i][j] <<endl;
            if(i % 2 == 0) {
                if(a[i][j] > nums[k]) {
                    if(i == x - 1) {
                        cout << -1<<endl;
                        i = 0;
                        j = y - 1;
                        break;
                    }
                    j = 0;
                    i++;
                } else if (a[i][j] < nums[k]) {
                    if(j == 0) {
                        cout << -1<<endl;
                        i = 0;
                        j = y - 1;
                        break;
                    }
                    j--;
                }
                
            } else {
                if(a[i][j] < nums[k]) {
                    if(j == y - 1) {
                        cout << -1<<endl;
                        i = 0;
                        j = y - 1;
                        break;
                    }
                    j++;
                } else if (a[i][j] > nums[k]) {
                    if(i == x - 1) {
                        cout << -1<<endl;
                        i = 0;
                        j = y - 1;
                        break;
                    }
                    i++;
                    j = y - 1;
                }
            }
            
            if(a[i][j] == nums[k]) {
                cout << i << " " << j <<endl;
                i = 0;
                j = y - 1;
                break;
            } 
        }
    }
}