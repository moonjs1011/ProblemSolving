#include<iostream>
#include<vector>
using namespace std;
vector<char>seq;
class stack{
private:
    int *arr;
    int capacity;
    int size;
    int top;
public:
    stack(int N){
        arr = new int[N];
        capacity = N;
        this->size=0;
        top =-1;
    }
    bool empty(){
        return (size==0)?true : false;
    }
    bool is_full(){
        return (size>=capacity) ? true : false;
    }
    void push(int ele){
        if(is_full()){
            cout<<"Full"<<"\n";
            return;
        }
        else{
            arr[++top] = ele;
            size++;
        }
    }
    int get_top(){
        return arr[top];
    }
    int pop(){
       if(empty()){
           cout<<"empty"<<"\n";
           return -1;
       }
       else{
           size--;
           return arr[top--];
       }
    }
};

int main(){
    int N;cin>>N;
    stack st(N);
    int cnt=1;
    while(N--){
        int input;
        cin>>input;
        while(cnt<=input){
            st.push(cnt);
            seq.push_back('+');
            cnt++;
        }
        if(st.get_top()==input){
            st.pop();
            seq.push_back('-');
        }
        else{
            cout<<"NO"<<"\n";
            return 0;
        }
    }
    for(int i=0;i<seq.size();i++)
        cout<<seq[i]<<"\n";
}