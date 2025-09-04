#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

struct Obj{
    ll ru,fa1,fa2;
};

ll N,M;
vector<Obj> ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    cout << ans.size() << "\n";
    for(Obj i : ans) cout << i.ru << " " << i.fa1 << " " << i.fa2 << "\n";
}