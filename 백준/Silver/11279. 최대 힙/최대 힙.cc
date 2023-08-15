#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
/*-------using heap-------

class heap {
private:
vector<int> v;
int back_index;
public:
heap() {
    v.push_back(-999); //dummy element
    back_index=0;
}

void upHeap(int index) {
    int parent = index / 2;
    if (index != 1 && v[index] > v[parent]) {
        swap(v[index], v[parent]);
        upHeap(parent);
    }
}

void insert(int value) {
    v.push_back(value);
    back_index++;
    upHeap(back_index);
}

void downHeap(int index) {
    int left = index * 2;
    int right = index * 2 + 1;
    int max_index = index;

    if (left <= back_index && v[max_index]<v[left]) {
        max_index = left;
    }
    if (right <=back_index && v[max_index]<v[right]) {
        max_index = right;
    }
    if (max_index != index) {
        std::swap(v[index], v[max_index]);
        downHeap(max_index);
    }
}

bool empty() {
    return v.size() <= 1;
}

int pop() {
    if (empty())
        return 0;
    int top = v[1];
    swap(v[1], v[back_index]);
    v.pop_back();
    back_index--;
    downHeap(1);
    return top;
}
};

int main() {
ios::sync_with_stdio(NULL);
cin.tie(NULL);
cout.tie(NULL);
 
 
int N;
cin >> N;
heap myheap;
while (N--) {
    int x;
    cin >> x;
    if (x == 0) {
        int res = myheap.pop();
        cout << res << "\n";
    } else {
        myheap.insert(x);
    }
}
 
}
*/


 /*---------using priority queue-----------
    int N;
    cin>>N;
    priority_queue<int> pq;
    while(N--){
       int x;
       cin>>x;
       if(x==0){
           if(!pq.empty()) {
               int top = pq.top();
               pq.pop();
               cout << top << "\n";
           }
           else cout<<0<<"\n";
       }
       else{
           pq.push(x);
       }
    }
     */
