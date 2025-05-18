#include <string>
#include <vector>

using namespace std;
int answer=0;
void dfs(vector<int> numbers,int num,int target,int index){
    if(numbers.size()-1==index){
        if(target==num)
            answer++;
        return;
    }
    
    index+=1;
    dfs(numbers,num + numbers[index],target,index);
    dfs(numbers,num - numbers[index],target,index);
}
int solution(vector<int> numbers, int target) {
    int index=0;
    dfs(numbers,numbers[index],target,index);
    dfs(numbers,-numbers[index],target,index);
    return answer;
}