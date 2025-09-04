#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 151010;
ll N,M,K,arr[SZ][3],DP[SZ][1 << 3],tmp[SZ],ans = INF;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<3;i++){
        for(int j = 1;j<=N;j++){
            cin >> arr[j][i];
            arr[j][i] += arr[j-1][i];
        }
    }
    for(int i = 0;i<3;i++){
        for(int j = 1;j<=N;j++){
            DP[j][1 << i] = arr[j][i];
        }
    }
    for(int i = 3;i<7;i++){
        if(__builtin_popcount(i) == 2){
            for(int k = 0;k<3;k++){
                if((i & (1 << k))){
                    for(int j = 2;j<=N;j++){
                        tmp[j] = max(DP[j-1][i^(1 << k)] + arr[j][k] - arr[j-1][k],tmp[j-1] + arr[j][k] - arr[j-1][k]);
                    }
                    for(int j = 2;j<=N;j++){
                        DP[j][i] = max(DP[j][i],tmp[j]);
                    }
                }
            }
        }
    }
    for(int i = 0;i<3;i++){
        for(int j = 3;j<=N;j++){
            ans = min(ans,arr[j-1][(i+1)%3]+arr[j-1][(i+2)%3] - DP[j-1][7^(1 << i)] + arr[N][i] - arr[j-1][i]);
        }
    }
    cout << ans;
}