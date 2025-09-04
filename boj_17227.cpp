#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll DP[101010][2],N,M,in_deg[101010],out_deg[101010],ans = INT_MAX;
vector<ll> E[101010];
queue<ll> q;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    while(M--){
        int u,v;
        cin >> u >> v;
        E[v].push_back(u);
        in_deg[u]++;
        out_deg[v]++;
    }
    DP[N][1] = 1;
    q.push(N);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(int i : E[cur]){
            DP[i][0] += min(DP[cur][1],1ll);
            DP[i][1] = max(DP[i][1],DP[cur][0]);
            in_deg[i]--;
            if(in_deg[i] == 0){
                if(out_deg[i] == 0) ans = min(ans,DP[i][0]);
                q.push(i);
            }
        }
    }
    cout << ans;
}