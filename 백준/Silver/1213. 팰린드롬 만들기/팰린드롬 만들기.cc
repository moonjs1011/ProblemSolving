#include<iostream>

using namespace std;
int cnt[26];
/*
 * 1. counting을 한다. 알파벳 별로
 * 2. 홀수 케이스랑 짝수 케이스를 나눈다. str.size
 * 3-1 홀수 케이스 반드시 1개만 있는게 있을것, 그것을 찾고 가운데에 위치시킴
 */
int main(){
    string str;
    cin>>str;
    for(char ch : str){
        cnt[ch-'A']+=1; //카운팅
    }
    int mid = 0;
    int flag=0;
    string ret;
    for(char ch ='Z';ch>='A';ch--){
        if(cnt[ch-'A']&1){ //홀수케이스
            flag++;
            cnt[ch-'A']--;
            mid = int(ch);
        }
        if(flag>1) break;
        if(cnt[ch-'A']>=0 && cnt[ch-'A']){
            for(int i=0;i<cnt[ch-'A'];i+=2){
                ret = ch + ret;
                ret+=ch;
            }
        }
    }
    if(flag>1) {
        cout << "I'm Sorry Hansoo\n";
        exit(0);
    }
    if(mid) ret.insert(ret.begin()+ret.size()/2,mid);
    cout<<ret<<"\n";

}