#include<iostream>
using namespace std;
/*  first approach W/A
string * solution(){
    string *arr = new string [10000001];
    int cur_child=1;
    int cur_parent=1;
    for(int i=1;i<10000001;i++){
        string str;
        str.append(to_string(cur_child));
        str.push_back('/');
        str.append(to_string(cur_parent));
        arr[i]=str;
        if(cur_parent==1){
            cur_parent = cur_child + 1;
            cur_child = 1;
        }
        else {
            cur_child++;
            cur_parent--;
        }
    }
    return arr;
}
int main(){
    string *ans = solution();
    int x;
    cin>>x;
    cout<<ans[x]<<"\n";
}*/
int main(){
    int N;
    cin>>N;
    int i=1;
    while(N>i){
        N-=i;
        i++;
    }
    if(i % 2 ==1) cout<< i+1-N << "/" << N<<"\n";
    else cout<< N<<"/"<<i+1-N<<"\n";
}