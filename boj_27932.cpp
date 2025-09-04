#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 101010;
ll N,M,K,arr[SZ];
bool check[SZ];

bool decision(ll m){
    ll res = 0;
    fill(check,check+N+1,0);
    for(int i = 1;i<N;i++){
        if(abs(arr[i]-arr[i+1]) > m) check[i] = check[i+1] = 1;
    }
    for(int i = 1;i<=N;i++) if(check[i]) res++;
    return res <= K;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    ll l = -1,r = 1e9;
    while(l<=r){
        ll m = (l+r)/2;
        if(decision(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l;
}