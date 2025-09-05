#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,L,K,x1,x2,x3;

vector<ll> ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K >> L;
    for(int i = 0;i<N;i++){
        cin >> x1 >> x2 >> x3;
        if(x1 < L || x2 < L || x3 < L) continue;
        if(x1 + x2 + x3 < K) continue;
        ans.push_back(x1);
        ans.push_back(x2);
        ans.push_back(x3);
    }
    cout << ans.size()/3 << "\n";
    for(ll i : ans) cout << i << " ";
}