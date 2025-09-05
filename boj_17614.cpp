#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll get(ll x){
    ll res = 0;
    while(x != 0){
        if(x%10 == 3 || x%10 == 6 || x%10 == 9) res++;
        x /= 10;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll sum = 0,N;
    cin >> N;
    for(int i = 1;i<=N;i++) sum += get(i);
    cout << sum;
}