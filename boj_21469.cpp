#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,M,town[101010],ans[101010];
pll shelter[101010];

bool cmp(const pll &u,const pll &v){
    if(u.first == v.first) return v.second < u.second;
    return u.first < v.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> town[i];
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> shelter[i].first;
        shelter[i].second = i+1;
    }
    sort(shelter,shelter+M,cmp);
    for(int i = 1;i<=N;i++){
        auto idx = lower_bound(shelter,shelter+M,make_pair(town[i],1),cmp);
        if(idx == shelter) ans[i] = (*idx).second;
        else if(idx == shelter+M) ans[i] = shelter[M-1].second;
        else{
            if(abs((*idx).first - town[i]) > abs((*(idx-1)).first - town[i])){
                ans[i] = (*(idx-1)).second;
            }
            else ans[i] = (*idx).second;
        }
        cout << ans[i] << " ";
    }
}