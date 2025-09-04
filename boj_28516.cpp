#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,arr[101010],prefix_sum[101010],c,k,l,r,ans = INT_MAX;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> c >> k;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    sort(arr+1,arr+N+1);
    for(int i = 1;i<=N;i++){
        prefix_sum[i] = arr[i];
        prefix_sum[i] += prefix_sum[i-1];
    }
    for(int i = N;i>=1;i--){
        if(c - k + 1 > arr[i]){
            ans = prefix_sum[N] - prefix_sum[i];
            break;
        }
    }
    while(l < N && arr[l] + k <= c){
        while(arr[l] + k >= arr[r+1] && r < N) r++;
        ans = min(ans,prefix_sum[r]-prefix_sum[l]);
        l++;
    }
    cout << ans;
}