#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long MOD = 1000000007;
long long seg[401010],N,x,y,cmd,M,lazy[401010],arr[101010];


void update(int s,int e,int node){
    seg[node] += (e-s+1)*lazy[node];
    if(s != e){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update1(int l, int r,int v,int s = 1, int e = N, int node = 1){
    update(s,e,node);
    if(s > r || e < l) return;
    if(s >= l && e <= r){
        lazy[node] += v;
        update(s,e,node);
        return;
    }
    int m = (s+e)/2;
    update1(l,r,v,s,m,node*2);
    update1(l,r,v,m+1,e,node*2+1);
    seg[node] = (seg[node*2] + seg[node*2+1]);
} 

long long query(int l,int r,int s = 1,int e = N,int node = 1){
    update(s,e,node);
    if(s > r || e < l) return 0;
    if(s>=l && e <= r) return seg[node];
    int m = (s+e)/2;
    return (query(l,r,s,m,node*2) + query(l,r,m+1,e,node*2+1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    cin >> M;
    while(M--){
        cin >> cmd;
        if(cmd == 1){
            cin >> x >> y;
            update1(x,y,1);
            if(y < N) update1(y+1,y+1,-(y-x+1));
        }
        else{
            cin >> x;
            cout << query(1,x) + arr[x] << "\n";
        }
    }
}