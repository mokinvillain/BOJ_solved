#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T,N,K;

ll solve(ll n){
    ll res = 0;
    while(n){
        if(n%2 == 1)  res++;
        n = n >> 1;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> N >> K;
        cout << solve(N)%K << "\n";
    }
}