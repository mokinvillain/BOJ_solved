#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll C,K;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> C >> K;
    ll p = pow(10,K);
    double tmp = (double)C/(double)p;
    C = round(tmp);
    C *= p;
    cout << C;
}