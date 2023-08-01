#include<iostream>
#include<stack>
using namespace std;
string solution(string buf){
    stack<char>st;
    for(int pos=0;pos<buf.size();pos++){
        if(buf[pos]=='[')
            st.push('[');
        else if(buf[pos]=='(')
            st.push('(');
        else if(buf[pos]==']'){
            if(st.empty())
                return "no";
            char top = st.top();
            if(top!='[')
                return "no";
            st.pop();
        }
        else if(buf[pos]==')'){
            if(st.empty())
                return "no";
            char top = st.top();
            if(top!='(')
                return "no";
            st.pop();
        }

    }
    if(!st.empty()) return "no";
    return "yes";
}
int main(){
    string buf;
    getline(cin,buf,'\n');
    while(buf!="."){
        string res = solution(buf);
        cout<<res<<"\n";
        getline(cin,buf,'\n');
    }
    return 0;
}