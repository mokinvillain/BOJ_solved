#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
ll DP[3010][3010],X,Y;

ll solve(int a,int b){
    if(a < 0) return 0;
    if(b < 0) return 0;
    if(DP[a][b] != -1) return DP[a][b];
    return DP[a][b] = (solve(a-2,b-1)*3 + solve(a,b-3))%MOD;
}

int main(){
    cin >> X >> Y;
    for(int i = 0;i<=3000;i++){
        for(int j = 0;j<=3000;j++){
            DP[i][j] = -1;
        }
    }
    DP[0][0] = 1;
    cout << solve(X,Y);
}