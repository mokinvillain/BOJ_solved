#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,L,R,arr[52][52];

bool bfs(){
    bool check[52][52];
    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=N;j++){
            check[i][j] = 0;
        }
    }
    queue<pll> q;
    vector<pll> v;
    bool res = 0;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(!check[i][j]){
                v.clear();
                q.push({i,j});
                v.push_back({i,j});
                check[i][j] = 1;
                while(!q.empty()){
                    pll tmp = q.front();
                    q.pop();
                    ll x = tmp.first,y = tmp.second;
                    if(abs(arr[x+1][y] - arr[x][y]) >= L && abs(arr[x+1][y] - arr[x][y]) <= R && !check[x+1][y]){
                        q.push({x+1,y});
                        check[x+1][y] = 1;
                        v.push_back({x+1,y});
                        res = 1;
                    }
                    if(abs(arr[x-1][y] - arr[x][y]) >= L && abs(arr[x-1][y] - arr[x][y]) <= R && !check[x-1][y]){
                        q.push({x-1,y});
                        check[x-1][y] = 1;
                        v.push_back({x-1,y});
                        res = 1;
                    }
                    if(abs(arr[x][y+1] - arr[x][y]) >= L && abs(arr[x][y+1] - arr[x][y]) <= R && !check[x][y+1]){
                        q.push({x,y+1});
                        check[x][y+1] = 1;
                        v.push_back({x,y+1});
                        res = 1;
                    }
                    if(abs(arr[x][y-1] - arr[x][y]) >= L && abs(arr[x][y-1] - arr[x][y]) <= R && !check[x][y-1]){
                        q.push({x,y-1});
                        check[x][y-1] = 1;
                        v.push_back({x,y-1});
                        res = 1;
                    }
                }
                ll tot = 0;
                for(pll i : v) tot += arr[i.first][i.second];
                for(pll i : v) arr[i.first][i.second] = tot/v.size();
            }
        }
    }
    return res;
}
int main(){
    ll ans = 0;
    cin >> N >> L >> R;
    for(int i = 0;i<=N;i++){
        arr[i][0] = INT_MAX;
        arr[0][i] = INT_MAX;
        arr[N+1][i] = INT_MAX;
        arr[i][N+1] = INT_MAX;
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin >> arr[i][j];
        }
    }
    while(bfs()){
        ans++;
    }
    cout << ans << "\n";
}