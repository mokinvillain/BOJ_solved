#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

struct Object{
    ll a,b,cost,idx;
};

const ll INF = 1e15,SZ = 101010;
ll N,M,K,arr[SZ],check[SZ],cur,cost_check[SZ];
vector<pll> E[SZ];
Object Edge[SZ];
vector<Object> las;
int disjoint_set[SZ],set_size[SZ];

bool cmp(Object &u,Object &v){
    return u.cost < v.cost;
}

int dfs(int x,int par){
    check[x] = ++cur;
    ll res = check[x];
    for(pll i : E[x]){
        if(i.first == par) continue;
        if(check[i.first]){
            res = min(res,check[i.first]);
        }
        else{
            ll tmp = dfs(i.first,x);
            if(tmp > check[x]) arr[i.second] = 1;
            res = min(res,tmp);
        }
    }
    return res;
}

void init(int n){
    iota(disjoint_set+1,disjoint_set + n+1,1);
}

int find(int x){
    if(disjoint_set[x] == x) return x;
    int tmp = find(disjoint_set[x]);
    set_size[x] = set_size[tmp];
    set_size[x] = tmp;
    return tmp;
}

bool Union(int x,int y){
    int par_x = find(x);
    int par_y = find(y);
    if(par_x == par_y) return 0;
    set_size[par_x] += set_size[par_y];
    set_size[par_y] = set_size[par_x];
    disjoint_set[par_x] = disjoint_set[par_y];
    return 1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 1;i<=M;i++){
        Edge[i].idx = i;
        cin >> Edge[i].a >> Edge[i].b >> Edge[i].cost;
    }
    for(int i = 1;i<=M;i++) arr[i] = 3;
    sort(Edge+1,Edge+M+1,cmp);
    init(N);
    for(int i = 1;i<=M;i++){
        if(Edge[i].cost != Edge[i-1].cost) las.clear();
        if(Union(Edge[i].a,Edge[i].b)){
            cost_check[Edge[i].a] = max(cost_check[Edge[i].a],Edge[i].cost);
            cost_check[Edge[i].b] = max(cost_check[Edge[i].b],Edge[i].cost);
            arr[Edge[i].idx] = 1;
            E[Edge[i].a].push_back({Edge[i].b,Edge[i].idx});
            E[Edge[i].b].push_back({Edge[i].a,Edge[i].idx});
            las.push_back(Edge[i]);
        }
        else if(max(cost_check[Edge[i].a],cost_check[Edge[i].b]) == Edge[i].cost){
            for(Object j : las) arr[j.idx] = 2;
            arr[Edge[i].idx] = 2;
            las.clear();
            E[Edge[i].a].push_back({Edge[i].b,Edge[i].idx});
            E[Edge[i].b].push_back({Edge[i].a,Edge[i].idx});
        }
    }
    dfs(1,-1);
    for(int i = 1;i<=M;i++) cout << arr[i] << "\n";
}