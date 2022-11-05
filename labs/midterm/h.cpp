#include<bits/stdc++.h>

using namespace std;

int cnt = 0;

struct hp {
    public:
        void insert(int val) {
            insert_(val);
        }
        void ans() {
            ans_();
        }
        void print() {
            print_();
        }
    private:
        void print_(){
            for(int i = 0; i < size; ++i){
                cout << vect[i] << " ";
            }
        }
        int size;
        vector<int> vect;
        void heapdown(int i) {
            if (i < size) {
                int swapId = i;
                int l = (i * 2) + 1;
                int r = (i * 2) + 2;

                if (l < size && vect[l] > vect[swapId]) {
                    swapId = l;
                }

                if (r < size && vect[r] > vect[swapId]) {
                    swapId = r;
                }

                if (swapId != i) {
                    swap(vect[i], vect[swapId]);
                    heapdown(swapId);
                }
            }
        }
        void heapup(int i) {
            if (i == 0) return;
            int p = (i - 1) / 2;
            if (vect[i] > vect[p]) {
                swap(vect[i], vect[p]);
                heapup(p); 
            }
        }
        void insert_(int val) {
            size++;
            if (vect.size() < size) {
                vect.push_back(val);
            }
            vect[size - 1] = val;
            heapup(size - 1);
        }

        void ans_() {
            for(int i = 1; i < vect.size(); i++) {
                if(i % 2 == 0) {
                    if(vect[i] > vect[i - 1]){
                        cnt++;
                    }
                }
            }
        }

       
};

int main() {
    hp* pq = new hp();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq->insert(x);
    }
    pq->ans();
    cout << cnt;
    
}
