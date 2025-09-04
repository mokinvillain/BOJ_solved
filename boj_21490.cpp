#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,K,cur,ans;
bool check[1010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 0;i<1001;i++){
        check[cur] = 1;
        cur += K;
        cur %= N;
    }
    for(int i = 0;i<N;i++){
        if(!check[i]) ans++;
    }
    cout << ans;
}