#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll uni_set[1010],N,M,K;
char c;
vector<pll> E[2],V[2];

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
    cin >> N >> M >> K;
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
        if(Union(tmp.first,tmp.second)){
            V[1].push_back(tmp);
            cur++;
        }
    }
    for(pll tmp : E[0]){
        bool check = Union(tmp.first,tmp.second);
        if(check) V[0].push_back(tmp);
        else if(cur > K){
            cur--;
            V[0].push_back(tmp);
        } 
    }
    if(cur == K){
        init();
        for(pll tmp : V[0]){
            Union(tmp.first,tmp.second);
            cout << tmp.first << " " << tmp.second << "\n";
        }
        for(pll tmp : V[1]){
            if(Union(tmp.first,tmp.second)) cout << tmp.first << " " << tmp.second << "\n";
        }
    }
    else cout << "0\n";
}