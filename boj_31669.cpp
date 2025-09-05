#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,M;
char arr[111][111];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++) cin >> arr[i][j];
    }
    for(int i = 0;i<M;i++){
        bool check = 0;
        for(int j = 0;j<N;j++){
            if(arr[j][i] == 'O') check = 1;
        }
        if(!check){
            cout << i+1;
            return 0;
        }
    }
    cout << "ESCAPE FAILED";
}