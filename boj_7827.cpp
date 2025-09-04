#include <bits/stdc++.h>

using namespace std;

int a,b,cnt,V,E_size,ans,T;
vector<int> E[2510];
bool check[2510];

void dfs(int x){
    if(check[x]) return;
    cnt++;
    check[x] = 1;
    for(int i : E[x]) dfs(i);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        ans = 0;
        cin >> V >> E_size;
        for(int i = 1;i<=V;i++) E[i].clear();
        while(E_size--){
            cin >> a >> b;
            E[a].push_back(b);
        }
        for(int i = 1;i<=V;i++){
            cnt = 0;
            for(int i = 1;i<=V;i++) check[i] = 0;
            dfs(i);
            ans += cnt-1;
        }
        cout << ans <<"\n";
    }
}