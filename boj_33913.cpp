#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
ll N,DP[1010101][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    DP[0][0] = 1;
    DP[0][1] = 0;
    for(int i = 1;i<=N;i++){
        DP[i][0] = DP[i-1][1]*2;
        DP[i][0] %= MOD;
        DP[i][0] += DP[i-1][0]*24;
        DP[i][0] %= MOD;
        DP[i][1] = DP[i-1][1]*24;
        DP[i][1] %= MOD;
        DP[i][1] += DP[i-1][0]*2;
        DP[i][1] %= MOD;
    } 
    cout << DP[N][0];
}