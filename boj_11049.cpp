#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,DP[510][510];
pll arr[510];

ll solve(int s,int e){
    if(DP[s][e]) return DP[s][e];
    if(s == e) return 0;
    ll r,c,d,tmp = INT_MAX;
    for(int i = s;i<e;i++){
        r = arr[s].first, c = arr[i].second, d = arr[e].second;
        tmp = min(tmp,solve(s,i)+solve(i+1,e)+r*c*d);
    }
    return DP[s][e] = tmp;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i].first >> arr[i].second;
    cout << solve(1,N);
}