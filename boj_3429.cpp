#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T,N,A[201010],seg[801010];

void press(){
    vector<int> C;
    for(int i=0; i<N; i++) C.push_back(A[i]);
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
    for(int i=0; i<N; i++){
        A[i] = lower_bound(C.begin(), C.end(), A[i])- C.begin();
    }
}

void Update(int x,int v,int s = 0,int e = N-1,int node = 1){
    if(s == e){
        seg[node] = v;
        return;
    }
    int m = (s+e)/2;
    if(x <= m) Update(x,v,s,m,node*2);
    else Update(x,v,m+1,e,node*2+1);
    seg[node] = max(seg[node*2],seg[node*2+1]);
}

int query(int l,int r,int s = 0,int e = N-1,int node = 1){
    if(s > r || e < l) return -1;
    if(s >= l && e <= r) return seg[node];
    int m = (s+e)/2;
    return max(query(l,r,s,m,node*2),query(l,r,m+1,e,node*2+1));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        int ans = 0;
        cin >> N;
        for(int i = 0;i<N;i++) cin >> A[i];
        fill(seg,seg+800000,0);
        press();
        for(int i = 0;i<N;i++){
            int tmp = query(0,max(0ll,A[i]-1));
            Update(A[i],tmp+1);
            ans = max(ans,tmp+1);
        }
        cout << ans << "\n";
    }
}