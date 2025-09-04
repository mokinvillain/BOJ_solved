#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,cnt;
char arr[30][30];
bool check[30][30];
vector<ll> ans;

void dfs(int x,int y){
    if(check[x][y]) return;
    cnt++;
    check[x][y] = 1;
    if((arr[x+1][y] - '0') == 1) dfs(x+1,y);
    if((arr[x-1][y] - '0') == 1) dfs(x-1,y);
    if((arr[x][y+1] - '0') == 1) dfs(x,y+1);
    if((arr[x][y-1] - '0') == 1) dfs(x,y-1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if((arr[i][j] - '0') && !check[i][j]){
                cnt = 0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(ll i : ans) cout << i << "\n";
}