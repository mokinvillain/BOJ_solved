#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,K,T;
pll DP[50];

ll solve(ll n,ll k){
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(k == DP[n].first) return DP[n].second;
    else if(k <= DP[n-2].first) return solve(n-2,k);
    return DP[n-2].second + solve(n-1,k-DP[n-2].first);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    DP[0] = {1,1};
    DP[1] = {1,0};
    for(int i = 2;i<=45;i++){
        DP[i].first = DP[i-1].first + DP[i-2].first;
        DP[i].second = DP[i-1].second + DP[i-2].second;
    }
    while(T--){
        cin >> N >> K;
        cout << solve(N,K) << "\n";
    }
}