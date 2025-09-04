#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 101010;
ll arr[SZ],tmp,ans,N;
string str;
ll seg[SZ << 2];

void init(int s = 1,int e = N,int node = 1){
    if(s == e){seg[node] = arr[s];return;}
    int m = (s+e)/2;
    init(s,m,node*2);
    init(m+1,e,node*2+1);
    seg[node] = min(seg[node*2],seg[node*2+1]);
}

void Update(int x,ll v,int s = 1,int e = N,int node = 1){
    if(s == e){seg[node] = v;return;}
    int m = (s+e)/2;
    if(x <= m) Update(x,v,s,m,node*2);
    else Update(x,v,m+1,e,node*2+1);
    seg[node] = min(seg[node*2],seg[node*2+1]);
}

ll query(int l,int r,int s = 1,int e = N,int node = 1){
    if(s >= l && e <= r) return seg[node];
    if(s > r || e < l) return INF;
    int m = (s+e)/2;
    return min(query(l,r,s,m,node*2),query(l,r,m+1,e,node*2+1));
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> str;
    N = str.size();
    if(N%2 != 0){
        cout << 0;
        return 0;
    }
    for(int i = 0;i<N;i++){
        if(str[i] == '(') arr[i+1]++;
        else arr[i+1]--;
        arr[i+1] += arr[i];
    }
    if(arr[N] == 0){
        cout << 0;
        return 0;
    }
    init();
    for(int i = 1;i<=N;i++){
        if(str[i-1] == '('){
            if(query(i,N) == 2) ans++;
        }
        else{
            if(query(i,N) == -2) ans++;
        }
        if(arr[i] < 0) break;
    }
    cout << ans;
}