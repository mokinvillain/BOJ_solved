#include <bits/stdc++.h>

using namespace std;

int N,a,b,c[201010];
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
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1,1);
    if(check) cout << 3;
    else cout << 2;
}