#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,a,b,cnt,cmd,r=-1,c=-1,arr[501010],M[1010101];
priority_queue<ll,vector<ll>,greater<>> pq[501010];
vector<pll> v;
pll m[501010];

void dfs(int x,int depth){
    m[x].first = ++cnt;
    v.push_back({10000000000,-1});
    v.push_back({arr[x],depth});
    while(!pq[x].empty()){
        dfs(pq[x].top(),depth+1);
    }
    m[x].second = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    for(int i = 1;i<N;i++){
        cin >> a >> b;
        pq[a].push(b);
    }
    dfs(1,1);
    v.push_back({10000000000,-1});
    for(ll i = 0;i<v.size();i++){
        if(i<=r) M[i] = min(r-i,M[c*2 - i]);
        while(i + M[i] + 1 < v.size() && i - M[i] - 1 >= 0 && v[i+M[i]+1].first == v[i-M[i]-1].first && v[i+M[i]+1].second == v[i-M[i]-1].second) M[i]++;
        if(i + M[i] > r){
            c = i;
            r = i + M[i];
        }
    }
    for(int i = 1;i<=N;i++){
        if(M[m[i].second])
    }
}