#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
ll S;
bool check[2000];

struct point{
    ll x,nxt,cost;
};

void bfs(ll start){
    queue<point> q;
    q.push({start,0});
    check[start] = 1;
    while(!q.empty()){
        point tmp = q.front();
        q.pop();
        if(tmp.x == S){
            cout << tmp.cost;
            return;
        }
        if(tmp.x <= 0) continue;
        if(!check[tmp.x-1]){
            check[tmp.x-1] = 1;
            q.push({tmp.x-1,tmp.x+tmp.nxt,tmp.cost+1});
        }
        if(tmp.x > 1000) continue;
        if(!check[tmp.x+tmp.nxt]){
            check[tmp.x+tmp.nxt] = 1;
            q.push({tmp.x+tmp.nxt,tmp.nxt,tmp.cost+1});
        }
        if(!check[tmp.x*2]){
            check[tmp.x*2] = 1;
            q.push({tmp.x*2,tmp.x,tmp.cost+2});
        }
    }
}
int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    cin >> S;
    bfs(1);
}