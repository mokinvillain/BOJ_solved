#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,K,ans;
pll arr[201010],cur[3];

bool cmp1(pll u,pll v){
    return u.second < v.second;
}
bool cmp2(pll u,pll v){
    return u.second > v.second;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 0;i<N;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr,arr+N,cmp1);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<K;j++){
            if(cur[j].second < arr[i].first){
                cur[j] = arr[i];
                ans++;
                break;
            }
        }
        sort(cur,cur+K,cmp2);
    }
    cout << ans;
}