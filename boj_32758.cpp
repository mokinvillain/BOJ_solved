#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,arr[101010],to_buy[101010],ans[101010];

bool decision(ll idx,ll m){
    ll sum = 0;
    if(arr[idx] == 1) return 1;
    while(m >= arr[idx]){
        ll t = m;
        sum += t - t%arr[idx];
        m += m/arr[idx];
        m -= t - t%arr[idx];
    }
    sum += m;
    return sum >= to_buy[idx];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    for(int i = 1;i<=N;i++) cin >> to_buy[i];
    for(int i = 1;i<=N;i++){
        ll l = 1,r = 1e9;
        while(l <= r){
            ll m = (l+r)/2;
            if(decision(i,m)) r = m - 1;
            else l = m + 1;
        }
        if(to_buy[i] == 0) ans[i] = 0;
        else ans[i] = l;
    }
    for(int i = 1;i<=N;i++) cout << ans[i] << " ";
}