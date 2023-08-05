#include<iostream>
using namespace std;
void sort(int *arr,int size){
    for(int i=0;i<size;i++)
        for(int j=i;j<size;j++){
            if(arr[i]<arr[j]){
                int temp =arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
}
int main(){
    int A,B,C;
    int *arr = new int[3];
    for(int i=0;i<3;i++)
        cin>>arr[i];
    sort(arr,3);
    cout<<arr[1]<<"\n";
}