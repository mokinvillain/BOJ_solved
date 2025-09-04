#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll uni_set[1010],N,M,K;
char c;
vector<pll> E[2];

void init(){
    for(int i = 1;i<=N;i++) uni_set[i] = i;
}

int find(int x){
    if(uni_set[x] == x) return x;
    return uni_set[x] = find(uni_set[x]);
}

bool Union(int u,int v){
    int par_u = find(u),par_v = find(v);
    if(par_u != par_v){
        uni_set[par_u] = uni_set[par_v];
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(cin >> N >> M >> K){
        if(N == 0) break;
        init();
        E[0].clear();
        E[1].clear();
        int u,v,cur = 0;
        while(M--){
            cin >> c >> u >> v;
            if(c == 'R') E[0].push_back({u,v});
            else E[1].push_back({u,v});
        }
        for(pll tmp : E[1]){
            if(Union(tmp.first,tmp.second)) cur++;
        }
        for(pll tmp : E[0]){
            if(!Union(tmp.first,tmp.second) && cur != K) cur--;
        }
        if(cur == K) cout << "1\n";
        else cout << "0\n";
    }
}