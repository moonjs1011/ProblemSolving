#include<iostream>
#include<cmath>
using namespace std;
bool solution(int x,int y, int z){
    int pow_x = pow(x,2) ;
    int pow_y = pow(y,2) ;
    int pow_z = pow(z,2) ;

    if(pow_x == pow_y + pow_z )
        return true;
    else
        return false;
}
int main() {
    int x,y,z;
    cin>>x>>y>>z;
    while(x!=0 && y!=0 && z!=0){
        int max_edge = max(max(x,y),z);
        bool res;
        if(max_edge==x)
            res = solution(x,y,z);
        else if(max_edge==y)
            res = solution(y,x,z);
        else if(max_edge==z)
            res = solution(z,x,y);

        if(res)
            cout<<"right"<<"\n";
        else
            cout<<"wrong"<<"\n";

        cin>>x>>y>>z;
    }
}