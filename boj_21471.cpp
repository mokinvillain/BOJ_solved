#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,M,mx_K;
bool check[300][300];
char arr[300][300];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++) cin >> arr[i][j];
    }
    mx_K = min(N,M);
    for(int k = 1;k<=mx_K;k++){
        
    }
}