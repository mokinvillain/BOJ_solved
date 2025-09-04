#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,ans,tmp;
pll cur,p;
string str;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> str;
    for(int i = 0;i<2*N;i++){
        if(str[i] == 'A') cur.first++;
        else cur.second++;
        if(i%2 == 0) p.first++;
        else p.second++;
        tmp += abs(p.first-cur.first);
        tmp += abs(p.second-cur.second);
    }
    ans = tmp;
    tmp = 0;p = {0,0};cur = {0,0};
    for(int i = 0;i<2*N;i++){
        if(str[i] == 'A') cur.first++;
        else cur.second++;
        if(i%2 == 1) p.first++;
        else p.second++;
        tmp += abs(p.first-cur.first);
        tmp += abs(p.second-cur.second);
    }
    ans = min(tmp,ans);
    cout << ans/2;
}