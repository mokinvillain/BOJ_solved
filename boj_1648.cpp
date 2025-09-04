#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 9901;
ll DP[225][1 << 14],N,M;

ll solve(ll i,ll mask){
    if(i == N*M){
        if(mask == 0) return 1;
        return 0;
    }
    if(DP[i][mask] != -1) return DP[i][mask];
    DP[i][mask] = 0;
    if(mask & 1) return DP[i][mask] = solve(i+1,mask >> 1)%MOD;
    if(i%M != M-1 && (mask & 2) == 0) DP[i][mask] += solve(i+2,mask >> 2);
    DP[i][mask] += solve(i+1,(mask >> 1) | (1 << M-1));
    DP[i][mask] %= MOD;
    return DP[i][mask];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(DP,-1,sizeof(DP));
    cin >> N >> M;
    cout << solve(0,0);
}