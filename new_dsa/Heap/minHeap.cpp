#include<iostream>
#include<queue>
using namespace std;

int arr[] = {9,1,6,5,3,8};
int N = 6;
void Heapify(int i){
    int l = i*2 + 1;
    int r = i*2 + 2;
    int smallest = i;
    if(l < N && arr[i] > arr[l]){
        smallest = l;
    }
    if(r < N && arr[smallest] > arr[r] ){
        smallest = r;
    }
    if(smallest != i){
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        Heapify(smallest);
    }
}

void MinHeap(){
    for(int i=(N/2)-1;i>=0;i--){
        Heapify(i);
    }
}

void printHeap(){
    for(int i = 0;i<N;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int deleteTop(){
    int x = arr[0];
    arr[0] = arr[N-1];
    N--;
    MinHeap();
    return x;
}
void heapSort(){
    for(int i=N-1;i>=0;i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        N--;
        MinHeap();
    }
}
struct Comparator{
    bool operator ()(const int n,const int m){
        return n > m;
    }
};
int main(){
    cout << "Before Heapify:" << endl;
    printHeap();
    MinHeap();
    cout << endl;
    cout << " After Heapify:" << endl;
    printHeap();
    int n = N;
    heapSort();
    N = n;
    printHeap();

    priority_queue<int,vector<int>,Comparator> que;
    que.push(12);
    que.push(13);
    que.push(15);
    que.push(9);
    cout << que.top() << endl;
    que.pop();
    cout << que.top() << endl;

}