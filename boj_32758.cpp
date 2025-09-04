#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,arr[101010],to_buy[101010],ans[101010];

bool decision(ll idx,ll m){
    ll sum = 0,t = 0;
    if(arr[idx] == 1) return 1;
    while(m != 0){
        sum += m;
        t += m%arr[idx];
        if(t >= arr[idx]){
            sum += t/arr[idx];
            t %= arr[idx];
        }
        m /= arr[idx];
    }
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
        ans[i] = l;
    }
    for(int i = 1;i<=N;i++) cout << ans[i] << " ";
}