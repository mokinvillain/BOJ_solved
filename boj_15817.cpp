#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,K,DP[101][10101];
pll arr[10101];
vector<pll> v;

int main(){
    cin >> N >> K;
    for(int i = 1;i<=N;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    DP[0][0] = 1;
    for(int i = 1;i<=N;i++){
        for(int k = 0;k<=10000;k++) DP[i][k] = DP[i-1][k];
        for(int j = 1;j<=arr[i].second;j++){
            for(int k = 0;k<=10000;k++){
                if(k >= arr[i].first*j) DP[i][k] += DP[i-1][k-arr[i].first*j];
            }
        }
    }
    cout << DP[N][K];
}