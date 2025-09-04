#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,K,arr[501010],seg[2101010],D,mod[501010],DP[501010],ans;

void Update(int x,int v,int s = 1,int e = 500000,int node = 1){
    if(s == e){
        seg[node] = v;
        return;
    }
    int m = (s+e)/2;
    if(x <= m) Update(x,v,s,m,node*2);
    else Update(x,v,m+1,e,node*2+1);
    seg[node] = max(seg[node*2],seg[node*2+1]);
}

int query(int l,int r,int s = 1,int e = 500000,int node = 1){
    if(s > r || e < l) return -1;
    if(s >= l && e <= r) return seg[node];
    int m = (s+e)/2;
    return max(query(l,r,s,m,node*2),query(l,r,m+1,e,node*2+1));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K >> D;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    for(int i = 1;i<=N;i++){
        mod[arr[i]%K]++;
        ll tmp = query(max(1ll,arr[i]-D), min(500000ll,arr[i]+D));
        tmp = max(mod[arr[i]%K],tmp+1);
        Update(arr[i],tmp);
        mod[arr[i]%K] = tmp;
        ans = max(tmp,ans);
    }
    cout << ans;
}