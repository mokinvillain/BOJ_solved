#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,M,arr[101010];
bool rev;
unordered_map<ll,deque<ll>> m;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    for(int i = 1;i<=N;i++){
        m[arr[i]].push_back(i);
    }
    sort(arr+1,arr+N+1,greater<>());
    for(int i = 1;i<=M;i++){
        if(!rev){
            cout << m[arr[i]].front() << "\n";
            m[arr[i]].pop_front();
        } 
        else{
            cout << m[arr[i]].back() << "\n";
            m[arr[i]].pop_back();
        }
        if(arr[i]%7 == 0) rev = !rev;
    }
}
