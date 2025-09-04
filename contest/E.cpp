#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,ans;
vector<pll> E[501010];
vector<unordered_map <ll,ll>&> m;

void dfs(int cur,int par, int XOR){
    ll res = 0;
    for(pll i : E[cur]){
        if(i.first != par){
            dfs(i.first,cur, XOR^i.second);
            for(auto it : m[i.first]) m[cur][XOR^it.first^i.second] += it.second;
        }
    }
    m[cur][XOR]++;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    m.resize(501010);
    cin >> N;
    for(int i = 1;i<N;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }
    dfs(1,-1,0);
    for(auto it : m[1]){
        ans += (it.second)*(it.second-1)/2;
    }
    cout << ans;
}