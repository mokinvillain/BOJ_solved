#include <bits/stdc++.h>

using namespace std;

int N,a,b,c[201010],k,V;
vector<int> E[201010];
bool check;

void dfs(int x,int color){
    if(c[x]){
        if(c[x] != color) check = 1;
        return;
    }
    c[x] = color;
    for(int i : E[x]) dfs(i,3-color);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> k;
    while(k--){
        check = 0;
        cin >> N >> V;
        for(int i = 1;i<=N;i++){
            c[i] = 0;
            E[i].clear();
        }
        for(int i = 0;i<V;i++){
            cin >> a >> b;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        for(int i = 1;i<=N;i++){
            if(!c[i]) dfs(i,1);
        }
        if(check) cout << "NO\n";
        else cout << "YES\n";
    }
}