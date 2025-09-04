#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,fibo[51] = {1,1},a,b,tmp1,tmp2,T;

ll gcd(ll x,ll y){
    if(x%y == 0) return abs(y);
    return gcd(y,x%y);
}

tuple<ll,ll,ll> ext_gcd(ll a, ll b){
     if(b == 0) return {a, 1, 0};
     auto [g,x,y] = ext_gcd(b, a % b);
     return {g, y, x- a/b * y};
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio();
    for(int i = 2;i<=50;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cin >> T;
    while(T--){
        cin >> N;
        int i = 0;
        while(fibo[i] + fibo[i+1] <= N){
            i++;
        }
        auto [g,x,y] = ext_gcd(fibo[i],fibo[i+1]);
        x *= N;
        y *= N;
        while(x > y){
            x -= fibo[i+1];
            y += fibo[i];
        }
        cout << x << " " << y << "\n";
    }
}