#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 201010;
ll N,M,K,arr[SZ],T,ans;
vector<ll> v;
ll seg[SZ << 2];

void init(int s = 1,int e = N,int node = 1){
    if(s == e){seg[node] = arr[s];return;}
    int m = (s+e)/2;
    init(s,m,node*2);
    init(m+1,e,node*2+1);
    seg[node] = max(seg[node*2],seg[node*2+1]);
}

void Update(int x,ll v,int s = 1,int e = N,int node = 1){
    if(s == e){seg[node] += v;return;}
    int m = (s+e)/2;
    if(x <= m) Update(x,v,s,m,node*2);
    else Update(x,v,m+1,e,node*2+1);
    seg[node] = max(seg[node*2],seg[node*2+1]);
}

ll query(int x,int s = 1,int e = N,int node = 1){
    if(s == e) return s;
    int m = (s+e)/2;
    if(seg[node*2] > seg[node*2+1]) return query(x,s,m,node*2);
    else if(seg[node*2])
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    for(int tc = 1;tc<=T;tc++){
        cin >> N;
        ans = 0;
        v.clear();
        for(int i = 1;i<=N;i++){
            cin >> arr[i];
            if(arr[i] == 0) v.push_back(i);
        }
        init();
        for(int i : v){
            int idx = query(i);
            cout << idx << " ";
            ans += abs(i - idx);
            Update(idx,-1);
        }
        cout << "Case #" << tc << "\n";
        cout << ans << "\n";
    }
}