#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = -1e9;
ll N,M,arr[101010];
pll seg[601010];

void init(int s = 1,int e = N,int node = 1){
    if(s == e){
        seg[node] = {arr[s],arr[s]};
        return;
    }
    int m = (s+e)/2;
    init(s,m,node*2);
    init(m+1,e,node*2+1);
    seg[node].first = max(seg[node*2].first,seg[node*2+1].first);
    seg[node].second = max(seg[node*2].second,seg[node*2+1].second);
    seg[node].second = max(seg[node].second,seg[node*2].first+seg[node*2+1].first);
}

void Update(ll x,ll v,int s = 1,int e = N,int node = 1){
    if(s == e){
        seg[node] = {v,v};
        return;
    }
    int m = (s+e)/2;
    if(x <= m) Update(x,v,1,m,node*2);
    else Update(x,v,m+1,e,node*2+1);
    seg[node].first = max(seg[node*2].first,seg[node*2+1].first);
    seg[node].second = max(seg[node*2].second,seg[node*2+1].second);
    seg[node].second = max(seg[node].second,seg[node*2].first+seg[node*2+1].first);
}

pll query(int l,int r,int s = 1,int e = N,int node = 1){
    if(s >= l && e <= r) return seg[node];
    if(s > r || e < l) return {INF,INF};
    int m = (s+e)/2;
    pll res,res1 = query(l,r,s,m,node*2),res2 = query(l,r,m+1,e,node*2+1);
    res.first = max(res1.first,res2.first);
    res.second = max(res1.second,res2.second);
    res.second = max(res.second,res1.first + res2.first);
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    init();
    cin >> M;
    while(M--){
        ll cmd,p,q;
        cin >> cmd >> p >> q;
        if(cmd == 1) Update(p,q);
        else cout << query(p,q).second << "\n";
    }
}
