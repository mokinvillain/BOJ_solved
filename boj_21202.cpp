#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,M,army[201010],ans,a,b;
vector<ll> E[201010];
bool check[201010];
priority_queue<pll> pq;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    while(M--){
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int i = 1;i<=N;i++) cin >> army[i];
    pq.push({-army[1],1});
    check[1] = 1;
    ans += army[1];
    while(!pq.empty()){
        pll cur = pq.top();
        pq.pop();
        if(-cur.first < ans) ans += -cur.first;
        for(int i : E[cur.second]){
            if(!check[i]){
                check[i] = 1;
                pq.push({-army[i],i});
            }
        }
    }
    cout << ans << "\n";
}