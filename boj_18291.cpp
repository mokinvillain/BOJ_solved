#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;
ll N,M,K,T;

ll PowMod(ll a, ll b, ll c){
    if(c == 1) return 0;
    ll res = 1;
    for(a%=c; b; b >>= 1, a = a * a % c) if(b & 1) res = res * a % c;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> N;
        if(N == 1 || N == 2) cout << "1\n";
        else cout << PowMod(2,N-2,MOD) << "\n";
    }
}