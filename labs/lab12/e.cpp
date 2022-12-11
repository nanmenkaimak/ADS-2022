#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 505 , inf = 2e9 + 7;

int a[N][N];

int main() {
    int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	
	for(int v = 1; v <= n; v ++) {
		vector<int> d(n+1, inf);
		d[v] = 0;
		vector<int> p(n+1, -1);
		int V;
		for(int i = 1; i <= n; i ++) {
			V = -1;
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= n; j ++) {
					if(a[i][j] == 10000) continue;
					if (d[i] < inf) {
						if (d[j] > d[i] + a[i][j]) {
							d[j] = max (-inf, d[i] + a[i][j]);
							p[j] = i;
							V = j;
						}
					}
				}
			}
		}
	 
	 	if(V == -1) {
	 		continue;
	 	}
		else {
			int st = V;
			for(int i = 1; i <= n; i ++)
				st = p[st];
	 
	 
	 		vector<int> vec;
	 		int cur = st;
	 		while(1) {
	 			vec.push_back(cur);
	 			if(cur == st && vec.size() > 1) break;
	 			cur = p[cur];
	 		}
	 		reverse(vec.begin(), vec.end());
	 
			cout << "YES\n";
			cout << vec.size() << '\n';
			for(auto to: vec) {
				cout << to << ' ';
			}
			return 0;
		}
	}
	cout << "NO";
}