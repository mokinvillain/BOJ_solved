#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

double A,B,C,D;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed;
    cout.precision(5);
    cin >> A >> B >> C >> D;
    double S = (A+B+C)/2;
    double Area = sqrt(S*(S-A)*(S-B)*(S-C));
    double R = Area/S;
    cout << Area*(1-(((R-D)/R)*((R-D)/R)));
}