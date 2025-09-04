#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,in_deg[111],K_0,K_1;
bool machine[111],p,check[111];
vector<ll> E[111],ans_0,ans_1,tmp;
queue<ll> q;

int main(){
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> machine[i];
        ll k,v;
        cin >> k;
        in_deg[i] = k;
        for(int j = 0;j<k;j++){
            cin >> v;
            E[v].push_back(i);
        }
    }
    for(int i = 1;i<=N;i++){
        if(!machine[i] && in_deg[i] == 0){
            check[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        ans_0.push_back(cur);
        for(ll i : E[cur]){
            in_deg[i]--;
        }
        for(int i = 1;i<=N;i++){
            if(machine[i] == p && !check[i] && in_deg[i] == 0){
                tmp.push_back(i); 
                check[i] = 1;
            }
        }
        if(q.empty() && tmp.size() == 0){
            K_0++;
            p = !p;
            for(int i = 1;i<=N;i++){
                if(machine[i] == p && !check[i] && in_deg[i] == 0){
                    tmp.push_back(i); 
                    check[i] = 1;
                }
            }
            for(ll i : tmp) q.push(i);
            tmp.clear();
        }
        else{
            for(ll i : tmp) q.push(i);
            tmp.clear();
        }
    }
    fill(check,check+N+1,0);
    fill(in_deg,in_deg+N+1,0);
    for(int i = 1;i<=N;i++){
        for(ll j : E[i]) in_deg[j]++;
    }
    for(int i = 1;i<=N;i++){
        if(machine[i] && in_deg[i] == 0){
            check[i] = 1;
            q.push(i);
        }
    }
    p = 1;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        ans_1.push_back(cur);
        for(ll i : E[cur]){
            in_deg[i]--;
        }
        vector<ll> tmp;
        for(int i = 1;i<=N;i++){
            if(machine[i] == p && !check[i] && in_deg[i] == 0){
                check[i] = 1;
                tmp.push_back(i); 
            }
        }
        if(q.empty() && tmp.size() == 0){
            K_1++;
            p = !p;
            for(int i = 1;i<=N;i++){
                if(machine[i] == p && !check[i] && in_deg[i] == 0){
                    check[i] = 1;
                    tmp.push_back(i); 
                }
            }
            for(ll i : tmp) q.push(i);
            tmp.clear();
        }
        else{
            for(ll i : tmp) q.push(i);
            tmp.clear();
        }
    }
    if(ans_0.size() < N){
        cout << K_1 - 1<< "\n";
        for(ll i : ans_1) cout << i << " ";
    }
    else if(ans_1.size() < N){
        cout << K_0 - 1<< "\n";
        for(ll i : ans_0) cout << i << " ";
    }
    else if(K_1 < K_0){
        cout << K_1 - 1 << "\n";
        for(ll i : ans_1) cout << i << " ";
    }
    else{
        cout << K_0 - 1 << "\n";
        for(ll i : ans_0) cout << i << " ";
    }
}