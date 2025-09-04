#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[201010],sum,prefix_sum[201010],mn = 0,mx = INT_MIN,N,tmp;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    for(int i = 1;i<=N;i++){
        cin >> tmp;
        if(tmp){
            sum += arr[i];
            prefix_sum[i] = -arr[i];
        }
        else prefix_sum[i] = arr[i];
        prefix_sum[i] += prefix_sum[i-1];
    }
    for(int i = 1;i<=N;i++){
        mx = max(mx,prefix_sum[i] - mn);
        mn = min(mn,prefix_sum[i]);
    }
    cout << sum + mx;
}