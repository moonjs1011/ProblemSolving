#include<iostream>
using namespace std;
int N,r,c;
int ans=0;
void traversal(int y,int x,int size){
    if(y==r && x==c){
        cout<<ans<<"\n";
        return;
    }
    if(r>=y && r<y+size && c>=x && c<x+size){
        traversal(y,x,size/2);
        traversal(y,x+size/2,size/2);
        traversal(y+size/2,x,size/2);
        traversal(y+size/2,x+size/2,size/2);
    }
    else{
        ans += size*size;
    }
}
int main(){
    cin>>N>>r>>c;
    traversal(0,0, 1<<N);
}