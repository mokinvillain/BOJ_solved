#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll DP[101010],H[101010],N,K,ans,a,b;
vector<ll> E[101010];

ll solve(int now,int par){
    DP[now] = H[now];
    for(int i : E[now]){
        if(i == par) continue;
        if(solve(i,now) == K){
            ans++;
            continue;
        }
        else{
            DP[now] += DP[i];
        }
    }
    return DP[now];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 1;i<=N;i++) cin >> H[i];
    for(int i = 0;i<N-1;i++){
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    solve(1,-1);
    cout << ans;
}