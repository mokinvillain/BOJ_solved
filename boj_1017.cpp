#include <bits/stdc++.h>

using namespace std;

int cur,arr[51];
bool SP[3010];
unordered_map<int,int> A,B;
unordered_map<int,bool> visited;
vector<int> ans,G[2];

void Sieve(){
    SP[0] = SP[1] = 1;
    for(int i = 2;i<=3000;i++){
        if(!SP[i]){
            for(int j = i*i;j<=3000;j+=i){
                SP[j] = 1;
            }
        }
    }
}

bool dfs(int a){
    visited[a] = true;
    if(a == cur || a == arr[0]) return false;
    for(int b : G[(a+1)%2]){
        if(b == cur || b == arr[0] || SP[a+b]) continue;
        if(!B[b] || (!visited[B[b]] && dfs(B[b]))){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N,tmp;
    Sieve();
    cin >> N;
    cin >> arr[0];
    for(int i = 1;i<N;i++){
        cin >> arr[i];
        G[arr[i]%2].push_back(arr[i]);
    }
    if(G[arr[0]%2].size()+1 != G[(arr[0]+1)%2].size()){
        cout << -1;
        return 0;
    }
    for(int i = 1;i<N;i++){
        bool check = 0;
        A.clear();
        B.clear();
        visited.clear();
        if(!SP[arr[0] + arr[i]]){
            cur = arr[i];
            for(int j = 0;j<G[arr[0]%2].size();j++){
                if(!A[G[arr[0]%2][j]]){
                    visited.clear();
                    if(!dfs(G[arr[0]%2][j])){
                        check = 1;
                        break;
                    }
                }
            }
            if(!check) ans.push_back(arr[i]);
        }
    }
    if(ans.size() == 0){
        cout << -1;
        return 0;
    }
    sort(ans.begin(),ans.end());
    for(int i : ans) cout << i << " ";
}
