#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

vector<ll> ans;
deque<ll> q;
ll card[401][3],N,D;
bool check[1010];
string str;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> D;
    fill(check,check+N+1,1);
    for(int i = 1;i<=N;i++) q.push_back(i);
    while(D--){
        for(int i = 1;i<=N/3;i++){
            for(int j = 0;j<3;j++){
                card[i][j] = q.front();
                q.pop_front();
            }
        }
        cin >> str;
        if(str == "first"){
            for(int i = 1;i<=N/3;i++){
                check[card[i][1]] = 0;
                check[card[i][2]] = 0;
            }
        }
        else if(str == "second"){
            for(int i = 1;i<=N/3;i++){
                check[card[i][0]] = 0;
                check[card[i][2]] = 0;
            }
        }
        else{
            for(int i = 1;i<=N/3;i++){
                check[card[i][0]] = 0;
                check[card[i][1]] = 0;
            }
        }
        for(int i = 0;i<3;i++){
            for(int j = 1;j<=N/3;j++){
                q.push_back(card[j][i]);
            }
        }
    }
    for(int i = 1;i<=N;i++) if(check[i]) ans.push_back(i);
    for(int i : ans) cout << i << " ";
}