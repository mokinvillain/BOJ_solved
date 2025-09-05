#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,H,W,ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> H;
    for(int i = 0;i<N;i++){
        cin >> W;
        if(H >= W) ans++;
    }
    cout << ans;
}