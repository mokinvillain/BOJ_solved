#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll DP[11][101010],N,K;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 1;i<=K;i++) DP[0][i] = 1;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=K;j++){
            DP[i][j] += DP[i-1][K];
            DP[i][j] %= MOD;
            for(int k = j*2;k<=K;k+=j){
                DP[i][j] -= DP[i-1][k];
                DP[i][j] += DP[i-1][k-1];
                DP[i][j] %= MOD;
            }
            DP[i][j] += DP[i][j-1];
            DP[i][j] %= MOD;
        }
    }
    cout << DP[N][K];
}