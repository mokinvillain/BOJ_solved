#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pll;

const ll INF = 1e15,SZ = 101010;
ll N,M,Q;

int Depth[SZ],Table[22][SZ],mx_Table[22][SZ],mn_Table[22][SZ];
vector<pll> G[SZ];

void DFS(int x,int par = -1){
    for(auto i : G[x]){
        if(i.first != par){
            Depth[i.first] = Depth[x] + 1;
            Table[0][i.first] = x;
            mx_Table[0][i.first] = i.second;
            mn_Table[0][i.first] = i.second;
            DFS(i.first,x);
        }
    }
}

void get_Table(){
    for(int i = 1;i<22;i++){
        for(int j = 1;j<=N;j++){
            Table[i][j] = Table[i-1][Table[i-1][j]];
            mx_Table[i][j] = max(mx_Table[i-1][j],mx_Table[i-1][Table[i-1][j]]);
            mn_Table[i][j] = min(mn_Table[i-1][j],mn_Table[i-1][Table[i-1][j]]);
        }
    }
}

pll get_LCA(int u,int v){
    if(Depth[u] < Depth[v]) swap(u,v);
    int diff = Depth[u] - Depth[v];
    pll res = {1010101,0};
    for(int i = 0;diff;i++,diff >>= 1){
        if(diff & 1){
            res.first = min(res.first,mn_Table[i][u]);
            res.second = max(res.second,mx_Table[i][u]);
            u = Table[i][u];
        }
    }
    if(u == v) return res;
    for(int i = 21;i>=0;i--){
        if(Table[i][u] != Table[i][v]){
            res.first = min(res.first,mn_Table[i][u]);
            res.second = max(res.second,mx_Table[i][u]);
            res.first = min(res.first,mn_Table[i][v]);
            res.second = max(res.second,mx_Table[i][v]);
            u = Table[i][u], v = Table[i][v];
        }
    }
    res.first = min(res.first,mn_Table[0][u]);
    res.second = max(res.second,mx_Table[0][u]);
    res.first = min(res.first,mn_Table[0][v]);
    res.second = max(res.second,mx_Table[0][v]);
    return res;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    int a,b,w;
    for(int i = 0;i<N-1;i++){
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    DFS(1);
    get_Table();
    cin >> M;
    while(M--){
        cin >> a >> b;
        pll res = get_LCA(a,b);
        cout << res.first << " " << res.second << "\n";
    }
}