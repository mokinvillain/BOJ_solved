#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;


struct compare{
    bool operator()(pll a, pll b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

pll arr[101010];
ll N,M,T,K;
priority_queue<pll,vector<pll>,compare> pq;

bool cmp(const pll &u,const pll &v){
    if(u.first == v.first) return u.second < v.second;
    return u.first < v.first;
}

bool cmp2(const pll &u,const pll &v){
    return u.first < v.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0;i<N;i++) cin >> arr[i].first >> arr[i].second;
        cin >> M;
        sort(arr,arr+N,cmp);
        for(int i = 0;i<N;i++){
            auto next = upper_bound(arr,arr+N,arr[i],cmp2);
            if((*next).second != (*(next-1)).second){
                pq.push(arr[i]);
            }
        }
        for(int i = 0;i<N;i++){
            if(arr[i].first == pq.top().first){
                arr[i] = pq.top();
                pq.pop();
            }
            cout << arr[i].first << " " << arr[i].second << "\n";
        }
        while(M--){
            cin >> K;
            //cout << arr[K-1].first << " " << arr[K-1].second << "\n";
        }
    }
}