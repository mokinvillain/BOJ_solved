#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long MOD = 1000000007;
long long seg[401010],N,x,y,cmd,v,M,lazy[401010];


void update(int s,int e,int node){
    if(lazy[node]%2) seg[node] = (e-s+1) - seg[node];
    if(s != e && lazy[node]){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update1(int l, int r,int s = 1, int e = N, int node = 1){
    update(s,e,node);
    if(s > r || e < l) return;
    if(s >= l && e <= r){
        lazy[node]++;
        update(s,e,node);
        return;
    }
    int m = (s+e)/2;
    update1(l,r,s,m,node*2);
    update1(l,r,m+1,e,node*2+1);
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
    cin >> N >> M;
    while(M--){
        cin >> cmd >> x >> y;
        if(cmd == 0){
            update1(x,y);
        }
        else{
            cout << query(x,y) << "\n";
        }
    }
}