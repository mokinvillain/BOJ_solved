#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()
vector<ll> seg[801010];
ll arr[201010],N,M,a,b,cmd;

void init(int s = 1,int e = N,int node = 1){
    if(s == e){
        seg[node].push_back(arr[s]);
        return;
    }
    int m = (s+e)/2;
    init(s,m,node*2);
    init(m+1,e,node*2+1);
    seg[node].resize(seg[node*2].size() + seg[node*2+1].size());
    merge(all(seg[node*2]), all(seg[node*2+1]), seg[node].begin());
}

void Update(int l,int r,int s = 1,int e = N,int node = 1){
    if(seg[node].size() == 0) return;
    if(s > r || e < l) return;
    if(s >= l && e <= r){
        seg[node].clear();
        return;
    }
    int m = (s+e)/2;
    Update(l,r,s,m,node*2);
    Update(l,r,m+1,e,node*2+1);
    seg[node].resize(seg[node*2].size() + seg[node*2+1].size());
    merge(all(seg[node*2]), all(seg[node*2+1]), seg[node].begin());
}

int query(int l,int r,ll v,int s = 1,int e = N,int node = 1){
    int K;
    if(seg[node].size() == 0) return 0;
    if(s > r || e < l) return 0;
    if(e <= r && s >= l){
        K = (upper_bound(seg[node].begin(),seg[node].end(),v) - lower_bound(seg[node].begin(),seg[node].end(),v));
        return K;
    }
    int m = (s+e)/2;
    return query(l,r,v,s,m,node*2) + query(l,r,v,m+1,e,node*2+1);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long k;
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    init(1,N,1);
    cin >> M;
    while(M--){
        cin >> cmd >> a >> b;
        if(cmd == 1){
            cin >> k;
            cout << query(a,b,k) << "\n";
        }
        else Update(a,b);
    }
}
