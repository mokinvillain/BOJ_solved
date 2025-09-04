#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll DP[210][210],N,K;
const ll MOD = 1000000000;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 1;i<=K;i++) DP[0][i] = 1;
    for(int i = 0;i<=N;i++) DP[i][1] = 1;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=K;j++){
            for(int k = 0;k<=i;k++){
                DP[i][j] += DP[i-k][j-1];
                DP[i][j] %= MOD;
            }
        }
    }
    cout << DP[N][K];
}