#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,arr[101010],ans,tmp,DP[1010101];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<N;i++) cin >> arr[i];
    ans = 1;
    for(int i = 0;i<N;i++){
        DP[arr[i]] = max(DP[arr[i]-1] + 1,DP[arr[i]]);
        ans = max(ans,DP[arr[i]]);
    }
    cout << ans;
}