#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll A,B,C,D;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> A >> B >> C >> D;
    B += C*2;
    A += D;
    cout << min(A/3,B/6);
}