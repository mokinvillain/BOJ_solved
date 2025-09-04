#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

struct Obj{
    ll st,ed,idx;
};

ll N,P[311];
pll DP[311];
Obj arr[311];

bool cmp(const Obj &u,const Obj &v){
    if(u.st == v.st) return u.ed < v.ed;
    return u.st < v.st;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> arr[i].st >> arr[i].ed;
        arr[i].ed += arr[i].st;
        arr[i].idx = i;
    }
    arr[0].st = -1,arr[0].ed = -1;
    sort(arr+1,arr+N+1,cmp);
    for(int i = 0;i<=N;i++){
        cout << arr[i].st << " " << arr[i].ed << "\n";
        for(int j = 0;j<i;j++){
            ll mn_j = min(DP[j].first,DP[j].second),mn_i = min(DP[i].first,DP[i].second);
            if(arr[j].ed <= arr[i].st){
                if(DP[j].first < DP[j].second && mn_j + 1 > mn_i){
                    DP[i] = DP[j];
                    if(DP[i].first <= DP[i].second) DP[i].first++;
                    else DP[i].second++;
                }
            }
            else{
                if(DP[j].first < DP[j].second && mn_j > mn_i){
                    DP[i] = DP[j];
                }
            }
        }
    }
    for(int i = 1;i<=N;i++) cout << DP[i].first << " " << DP[i].second << "\n";
}