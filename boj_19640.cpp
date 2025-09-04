#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct mem{
    ll D,H,idx,now;
};

bool operator<(const mem &u,const mem &v){
    if(u.D == v.D){
        if(u.H == v.H){
            return u.idx > v.idx;
        }
        return u.H < v.H;
    }
    return u.D < v.D;
}

queue<mem> q[101010];
priority_queue<mem> pq;
ll N,M,K;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> K;
    mem tmp;
    for(int i = 0;i<N;i++){
        cin >> tmp.D >> tmp.H;
        tmp.idx = i; tmp.now = i%M;
        q[i%M].push(tmp);
    }
    for(int i = 0;i<M;i++){
        tmp = q[i].front();
        pq.push(tmp);
        q[i].pop();
    }
    ll ans = 0;
    while(!pq.empty()){
        tmp = pq.top();
        if(tmp.idx == K){
            cout << ans;
            return 0;
        }
        pq.pop();
        if(!q[tmp.now].empty()){
            pq.push(q[tmp.now].front());
            q[tmp.now].pop();
        }
        ans++;
    }
    cout << ans;
}
