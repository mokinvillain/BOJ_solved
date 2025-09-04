#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,M,A[1010],B[1010],tmp,x,y,ans;
bool visited[1010];
vector<ll> G[1010];

bool dfs(int a){
    visited[a] = true;
    for(int b: G[a]){
        if(!B[b] || !visited[B[b]] && dfs(B[b])){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 1;i<=N;i++){
        cin >> tmp;
        for(int j = 0;j<tmp;j++){
            cin >> x;
            G[i].push_back(x);
        }
    }
    for(int i = 1;i<=N;i++){
        if(!A[i]){
            fill(visited,visited+N+1,0);
            if(dfs(i)) ans++;
        }
    }
    cout << ans;
}