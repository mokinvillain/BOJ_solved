#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pLL;

ll A,B;

ll gcd(ll a,ll b){
    if(a%b == 0) return b;
    return gcd(b,a%b);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> A >> B;
    if(A == 0 && B == 0) cout << 0;
    else if(A == 0){
        if(B == 1 || B == -1) cout << 1;
        else cout << 2;
    }
    else if(B == 0){
        if(A == 1 || A == -1) cout << 1;
        else cout << 2;
    }
    else if(gcd(abs(A),abs(B)) == 1) cout << 1;
    else cout << 2;
}
