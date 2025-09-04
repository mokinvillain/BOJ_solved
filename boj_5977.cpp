#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

const LL INF = 101010101010;
LL N,D,DP_seg[301010],arr[101010],tmp,ans,sum;

void Update(int x,LL v,int s = 0,int e = N,int node = 1){
    if(s == e){
        DP_seg[node] = v;
        return;
    }
    int m = (s+e)/2;
    if(x <= m) Update(x,v,s,m,node*2);
    else Update(x,v,m+1,e,node*2+1);
    DP_seg[node] = min(DP_seg[node*2],DP_seg[node*2+1]);
}

LL query(int l,int r,int s = 0,int e = N,int node = 1){
    if(s > r || e < l) return INF;
    if(s>=l && e <= r) return DP_seg[node];
    int m = (s+e)/2;
    return min(query(l,r,s,m,node*2),query(l,r,m+1,e,node*2+1));
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> D;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    for(LL i = 1;i<=N;i++){
        sum += arr[i];
        tmp = query(max(0LL,i-D-1),i-1);
        Update(i,tmp+arr[i]);
    }
    ans = query(N-D,N);
    cout << sum - ans;
}