#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll DP[1010][1010][2],N,root,ans;
pll child[1010];
bool check[1010];

void dfs(int cur){
    if(child[cur].first == 0 && child[cur].second == 0){
        DP[cur][1][0] = 1;
        DP[cur][0][1] = 1;
        return;
    }
    if(child[cur].first) dfs(child[cur].first);
    if(child[cur].second) dfs(child[cur].second);
    for(int i = 1;i<=1001;i++){
        DP[cur][i][0] += DP[child[cur].first][i-1][0]*DP[child[cur].second][i-1][0];
        DP[cur][i][0] %= MOD;
        DP[cur][i][0] += DP[child[cur].first][i-1][0]*DP[child[cur].second][i-1][1];
        DP[cur][i][0] %= MOD;
        DP[cur][i][0] += DP[child[cur].first][i-1][1]*DP[child[cur].second][i-1][0];
        DP[cur][i][0] %= MOD;
        DP[cur][i][0] += DP[child[cur].first][i-1][1]*DP[child[cur].second][i-1][1];
        DP[cur][i][0] %= MOD;
    }
    for(int i = 0;i<=1001;i++){
        DP[cur][i][1] += DP[child[cur].first][i][0]*DP[child[cur].second][i][0];
        DP[cur][i][1] %= MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> child[i].first >> child[i].second;
        check[child[i].first] = 1;
        check[child[i].second] = 1;
    }
    DP[0][0][0] = 1;
    for(int i = 1;i<=N;i++){
        if(!check[i]) root = i;
    }
    dfs(root);
    for(int i = 0;i<=N;i++){
        ans += DP[root][i][1] + DP[root][i][0];
        ans %= MOD;
    }
    cout << ans;
}