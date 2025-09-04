#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll arr[201010],Pn[2010101],ans,N,INF = 10101010101010;

int SP[5050505];
vector<pll> v;

void solve(ll cur,ll n){
    if(n == v.size()){
        Pn[cur] += cur;
        if(Pn[cur] >= cur*2) ans = max(ans,Pn[cur]);
        return;
    }
    for(int i = 0;i<=v[n].second;i++){
        ll k = pow(v[n].first,i);
        solve(cur*k, n+1);
    }
}

void Sieve(int n){
    for(int i=2; i<=n; i++){
        if(SP[i]) continue;
        for(int j=i; j<=n; j+=i) if(!SP[j]) SP[j] = i;
    }
}

vector<pll> Factorize(int n){
    vector<pll> res;
    while(n != 1){
        if(res.empty() || res.back().first != SP[n]) res.emplace_back(SP[n], 1);
        else res.back().second++;
        n /= SP[n];
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    Sieve(2000000);
    for(int i = 0;i<N;i++){
        cin >> arr[i];
        v = Factorize(arr[i]);
        solve(1,0);
    }
    cout << ans;
}