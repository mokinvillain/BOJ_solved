#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,M,K,arr[110][110],sum[10101],mx;
bool check[110][110];

void dfs(int x,int y){
    if(check[x][y]) return;
    check[x][y] = 1;
    sum[arr[x][y]]++;
    if(arr[x][y+1] == arr[x][y]) dfs(x,y+1);
    if(arr[x][y-1] == arr[x][y]) dfs(x,y-1);
    if(arr[x+1][y] == arr[x][y]) dfs(x+1,y);
    if(arr[x-1][y] == arr[x][y]) dfs(x-1,y);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> K;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            cin >> arr[i][j];
            mx = max(mx,arr[i][j]);
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(!check[i][j] && sum[arr[i][j]]){
                cout << "Wrong answer";
                return 0;
            }
            dfs(i,j);
        }
    }
    for(int i = 1;i<=mx;i++){
        if(sum[i] != K){
            cout << "Wrong answer";
            return 0;
        }
    }
    cout << "OK";
}