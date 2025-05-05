#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct Op{
    bool operator()(pair<int,int>a,pair<int,int>b){
        if(a.first == b.first)
            return a.second<b.second;
        else return a.first>b.first;
    }
};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>ans1(10001);
    vector<int>ans2(10001);
    vector<int>ans3(10001);
    int value = 1;
    for(int i=0;i<10001;i++){//1번 수포자
        if(value % 5 == 0 )
            value = 5;
        else value %=5;
        ans1[i] = value++;
    }
    int tmp2 = 1;
    for(int i=0;i<10001;i++){ //2번 수포자
        if(i%2==0)
            ans2[i] = 2;
        else{
            if(tmp2 == 2)
                tmp2 = 3;
            else if(tmp2 %5 == 0) tmp2= 5;
            else tmp2 %=5;
            ans2[i] = tmp2++;
        }
    }
    int arr[10] ={3,3,1,1,2,2,4,4,5,5};
    for(int i=0;i<10000;i+=2){
        ans3[i] = arr[i%10];
        ans3[i+1] = arr[i%10];
        
    }
    vector<pair<int,int>> v;
    v.push_back({0,1});
    v.push_back({0,2});
    v.push_back({0,3});
    for(int i=0;i<answers.size();i++){
        if(answers[i] == ans1[i])
            v[0].first++;
        if(answers[i]==ans2[i])
            v[1].first++;
        if(answers[i]==ans3[i])
            v[2].first++;
    }
    sort(v.begin(),v.end(),Op());
    if(v[0].first!=v[1].first)
        answer.push_back(v[0].second);
    else if(v[0].first==v[1].first&&v[1].first!=v[2].first){
        answer.push_back(v[0].second);
        answer.push_back(v[1].second);
    }
    else{
        answer.push_back(v[0].second);
        answer.push_back(v[1].second);
        answer.push_back(v[2].second);
    }
    return answer;
}

