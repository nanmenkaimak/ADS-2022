#include<bits/stdc++.h>

using namespace std;

struct hp {
    public:
        void insert(int val) {
            insert_(val);
        }
        void ans(int i, int val) {
            ans_(i, val);
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

        void ans_(int i, int val) {
            i = i - 1;
            vect[i] = vect[i] + val;
            int num = vect[i];
            heapup(i);
            int j = getIndex(num);
            cout << j << endl;
        }

        int getIndex(int num) {
            for(int i = 0; i < size; i++) {
                if(vect[i] == num) {
                    return i + 1;
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
    int q; cin >> q;

    while(q != 0) {
        q--;
        int index; 
        int key;
        cin >> index >> key;
        pq->ans(index, key);
    }
   
    pq->print();
}
