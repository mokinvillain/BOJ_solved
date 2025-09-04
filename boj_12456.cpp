#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
struct coffee{
    ll c,t,s;
};

coffee tmp;
vector<coffee> arr;
vector<pll> pa;
ll T,N,K,cur,ans;

bool cmp(const coffee &u,const coffee &v){
    return u.s < v.s;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    for(int tc = 1;tc<=T;tc++){
        arr.clear();
        cin >> N >> K;
        while(N--){
            cin >> tmp.c >> tmp.t >> tmp.s;
            arr.push_back(tmp);
        }
        cur = 1;
        ans = 0;
        cout << "Case #" << tc << ": " << ans << "\n";
    }
}