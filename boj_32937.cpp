#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,X,Y,D,ans,mx = -1,tmp;
pll arr[111];
bool DP[111][101010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> X >> Y >> D >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i].first >> arr[i].second;
    DP[0][0] = 1;
    for(int i = 1;i<=N;i++){
            for(int k = 0;k<=100000;k++){
                if(DP[i-1][k]) DP[i][k] = 1;
                for(int j = 1;j<=arr[i].first;j++){
                    if(k >= arr[i].second*j && DP[i-1][k-arr[i].second*j]) DP[i][k] = 1;
                }
            }
    }
    for(int i = 100000;i>=0;i--){
        if(DP[N][i]){
            if(mx == -1) {mx = min(D,(i/X)*Y); ans = i;continue;}
            tmp = min(D,(i/X)*Y);
            if(mx == tmp) ans = i;
            else{
                cout << ans;
                return 0;
            }
        }
    }
    if(mx > 0) cout << ans;
    else cout << 0;
}