#include<iostream>
#include<vector>
#include<string>
using namespace std;
void sort(int *arr,int N){
    for(int i=0;i<N;i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
void print(int *arr,int N){
    for(int i=0;i<N;i++)
        cout<<arr[i]<<"\n";
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int *arr = new int[N];
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,N);
    print(arr,N);
}