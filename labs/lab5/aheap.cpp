#include <iostream>

using namespace std;

unsigned long long heap[200010];
int size = 0;

void heapify(int i){
    int left = i + i + 1;
    int right = i + i + 2;
    int mx = i;

    if(left < size && heap[left] < heap[mx]){
        mx = left;
    }

    if(right < size && heap[right] < heap[mx]){
        mx = right;
    }

    if(mx != i){
        swap(heap[mx], heap[i]);
        heapify(mx);
    }


}

void build(){
    for(int i= size/2; i>=0; i--){
        heapify(i);
    }
}

void print(){
    for(int i=0; i<size; i++) {
        cout << heap[i] <<  " ";
    }
    cout << endl;
}

void deleteMin(){
    swap(heap[0], heap[size-1]);
    size--;
    heapify(0);
}

void insert(unsigned long long value){
    heap[size++] = value;
    int i = size - 1;
    while(i>0){
        int p = (i - 1)/2;
        if(heap[i] < heap[p]){
            swap(heap[i], heap[p]);
            i = p;
        } else{
            break;
        } 
    }

}

unsigned long long ans = 0;


int main(){
    cin >> size;
    for(int i=0; i<size; i++){
        cin >> heap[i];
    }

    build();

    while(size > 1){
        unsigned long long a = heap[0];
        deleteMin();
        unsigned long long b = heap[0];
        deleteMin();
        ans += (a + b);
        insert(a + b);
    }
    cout << ans;
    return 0;
}