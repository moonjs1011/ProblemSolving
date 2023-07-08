#include<iostream>
#include<vector>
#include<string>
using namespace std;
pair<int,int> solution(int h,int m,int t){
    if(m+t<60){
        m+=t;
    }
    else if(m+t>=60){
        h+= (m+t)/60;
        m= (m+t)%60;
        if(h>=24)
            h=h%24;
    }
    return {h,m};
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int hour,minute,takes;
    cin>>hour>>minute>>takes;
    pair<int,int> finish_time = solution(hour,minute,takes);
    cout<<finish_time.first<<" "<<finish_time.second;
}