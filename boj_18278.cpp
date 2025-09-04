#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 301010;
ll N,M,K,black,yellow;

ll B_seg[SZ << 2],Y_seg[SZ << 2],Q,ans,arr[SZ];
char tshirt[101010];

void Update1(int x,ll v,int s = 0,int e = SZ,int node = 1){
    B_seg[node] += v;
    if(s == e) return;
    int m = (s+e)/2;
    if(x <= m) Update1(x,v,s,m,node*2);
    else Update1(x,v,m+1,e,node*2+1);
    B_seg[node] = B_seg[node*2] + B_seg[node*2+1];
}

ll query1(int l,int r,int s = 0,int e = SZ,int node = 1){
    if(s >= l && e <= r) return B_seg[node];
    if(s > r || e < l) return 0;
    int m = (s+e)/2;
    return query1(l,r,s,m,node*2) + query1(l,r,m+1,e,node*2+1);
}

void Update2(int x,ll v,int s = 0,int e = SZ,int node = 1){
    Y_seg[node] += v;
    if(s == e) return;
    int m = (s+e)/2;
    if(x <= m) Update2(x,v,s,m,node*2);
    else Update2(x,v,m+1,e,node*2+1);
    Y_seg[node] = Y_seg[node*2] + Y_seg[node*2+1];
}

ll query2(int l,int r,int s = 0,int e = SZ,int node = 1){
    if(l > r) return 0;
    if(s >= l && e <= r) return Y_seg[node];
    if(s > r || e < l) return 0;
    int m = (s+e)/2;
    return query2(l,r,s,m,node*2) + query2(l,r,m+1,e,node*2+1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    for(int i = 1;i<=N;i++){
        cin >> tshirt[i];
        if(tshirt[i] == 'C') black++;
        else yellow++;
    }
    Update1(0,black);
    Update2(0,yellow);
    while(Q--){
        cin >> M >> K;
        if(tshirt[M] == 'C'){
            ans -= query2(0,arr[M]-1);
            Update1(arr[M],-1);
            arr[M] += K;
            ans += query2(0,arr[M]-1);
            Update1(arr[M],1);
        }
        else{
            ans -= query1(arr[M]+1,SZ);
            Update2(arr[M],-1);
            arr[M] += K;
            ans += query1(arr[M]+1,SZ);
            Update2(arr[M],1);
        }
        cout << ans << "\n";
    }
}