#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int solution(int i) {
    int sum = i;
    while(i!=0){
        sum+= i%10;
        i /=10;
    }
    return sum;
}

int main() {
    bool check[10001]{false};
    for (int i = 1; i <= 10000; i++){
        int n = solution(i);
        if(n<=10000)
            check[n]=true;
    }
    for(int i=1;i<=10000;i++){
        if(!check[i])
            cout<<i<<"\n";
    }
}
