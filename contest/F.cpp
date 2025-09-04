#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,DP[201010],mx;
pll arr[201010];
vector<ll> ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1,arr+N+1);
    for(int i = 1;i<=N;i++){
        DP[i] = max(DP[i-1] + arr[i].first*2 - arr[i-1].first,arr[i].first*3);
        mx = max(DP[i],mx);
    }
    for(int i = N;i>=1;i--){
        if(DP[i] == mx){
            if(DP[i] == DP[i-1] + arr[i].first*2 - arr[i-1].first){
                mx -= arr[i].first*2 - arr[i-1].first;
            }
            else mx -= arr[i].first*3;
            ans.push_back(arr[i].second);
        }
    }
    cout << ans.size() << "\n";
    for(int i : ans) cout << i << " ";
}