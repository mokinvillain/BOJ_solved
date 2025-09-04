#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;


pll arr[101010],solve[1010][2];
ll DP[1010][2],N,H,W,d1,d2,d3,d4,l;
bool cmp(const pll &u,const pll &v){
    if(u.first == v.first) return u.second < v.second;
    return u.first < v.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> H >> W;
    arr[0] = {1,1};
    for(int i = 1;i<=N;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr,arr+N+1,cmp);
    H = 1,l = 1;
    for(int i = 1;i<=N;i++){
        if(arr[i].first != arr[i-1].first){
            solve[H][0] = {arr[i-1].first,l};
            solve[H][1] = arr[i-1];
            l = arr[i].second;
            H++;
        }
    }
    solve[H][0] = {arr[N].first,l};
    solve[H][1] = arr[N];
    DP[1][1] = solve[1][1].second - 1;
    DP[1][0] = INT_MAX;
    for(int i = 2;i<=H;i++){
        d1 = abs(solve[i-1][0].second-solve[i][1].second);
        d2 = abs(solve[i-1][1].second-solve[i][1].second);
        d3 = abs(solve[i-1][1].second-solve[i][0].second);
        d4 = abs(solve[i-1][0].second-solve[i][0].second);
        W = (solve[i][0].first - solve[i-1][0].first)*100;
        DP[i][0] = min(DP[i-1][0]+d1,DP[i-1][1]+d2) + solve[i][1].second - solve[i][0].second + W;
        DP[i][1] = min(DP[i-1][1]+d3,DP[i-1][0]+d4) + solve[i][1].second - solve[i][0].second + W;
    }
    cout << min(DP[H][0],DP[H][1]);
}