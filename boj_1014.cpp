#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 110;
ll N,M,K,DP[SZ][1 << 12],T;
char arr[11][11];

ll solve(int x,int mask){
    if(x == N*M) return 0;
    if(DP[x][mask] != -1) return DP[x][mask];
    DP[x][mask] = solve(x+1,mask >> 1);
    int r = x/M,c = x%M;
    if(arr[r][c] == 'x' || (mask & 1)) return DP[x][mask];
    int tmp = 0;
    if(c == 0) tmp |= ((1 << (M+1)) | 2);
    else if(c == M-1) tmp |= (1 << M-1);
    else tmp |= (1 << (M+1)) | (1 << M-1) | 2;
    return DP[x][mask] = max(DP[x][mask],solve(x+1,(mask | tmp) >> 1)+1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        memset(DP,-1,sizeof(DP));
        cin >> N >> M;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++) cin >> arr[i][j];
        }
        cout << solve(0,0) << "\n";
    }
}