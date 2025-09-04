#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 101010;
ll N,M,K,arr[SZ];

ll cl(ll p,ll q){
    if(p%q == 0) return p/q;
    return p/q + 1;
}

bool decision(ll m){
    ll base = 0,to_solve = 0;
    for(int i = 0;i<N;i++){
        ll tmp = cl(arr[i],m);
        if(tmp == 1) base++;
        else to_solve += tmp - 2;
    }
    base--;
    return base >= to_solve;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<N;i++) cin >> arr[i];
    ll l = 1,r = 1e10;
    while(l <= r){
        ll m = (l+r)/2;
        if(decision(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l;
}