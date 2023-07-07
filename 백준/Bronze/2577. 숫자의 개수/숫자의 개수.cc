#include<iostream>
#include<vector>
using namespace std;
int * init_array(int size){
    int *array = new int[size];
    for(int i=0;i<size;i++)
        array[0];
    return array;
}
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int A,B,C;
    cin>>A>>B>>C;
    string result = to_string(A*B*C);
    int *count = init_array(10);
    for(int i=0;i<result.size();i++){
        count[result[i]-'0']+=1;
    }
    for(int i=0;i<10;i++)
        cout<<count[i]<<"\n";
}