#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e12;
ll DP[201010][2][2],track[501010][2],M,K,arr[201010],solve[501010][2],ans;
string str;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> M >> K;
    for(int i = 1;i<=K;i++) cin >> arr[i];
    for(int k = 1;k<=M;k++){
        cin >> str;
        for(int i = 0;i<str.size();i++){
            if(str[i] == '#') track[i][0] = INF;
            else track[i][0] = 1;
        }
        cin >> str;
        for(int i = 0;i<str.size();i++){
            if(str[i] == '#') track[i][1] = INF;
            else track[i][1] = 1;
        }
        solve[0][0] = track[0][0];
        solve[0][1] = track[0][0]+track[0][1];
        for(int i = 1;i<str.size();i++){
            solve[i][0] = min(solve[i-1][0],solve[i-1][1]+track[i][1]) + track[i][0];
            solve[i][1] = min(solve[i-1][1],solve[i-1][0]+track[i][0]) + track[i][1];
        }
        DP[k][0][1] = solve[str.size()-1][1];
        DP[k][0][0] = solve[str.size()-1][0];
        solve[0][1] = track[0][1];
        solve[0][0] = track[0][0] + track[0][1];
        for(int i = 1;i<str.size();i++){
            solve[i][0] = min(solve[i-1][0],solve[i-1][1]+track[i][1])+ track[i][0];
            solve[i][1] = min(solve[i-1][1],solve[i-1][0]+track[i][0])+ track[i][1];
        }
        DP[k][1][1] = solve[str.size()-1][1];
        DP[k][1][0] = solve[str.size()-1][0];
    }
    solve[1][1] = min(DP[arr[1]][0][1],DP[arr[1]][1][1]) - 1;
    solve[1][0] = min(DP[arr[1]][0][0],DP[arr[1]][1][0]) - 1;
    for(int i = 2;i<=K;i++){
        solve[i][1] = min(DP[arr[i]][0][1]+solve[i-1][0],DP[arr[i]][1][1]+solve[i-1][1]);
        solve[i][0] = min(DP[arr[i]][0][0]+solve[i-1][0],DP[arr[i]][1][0]+solve[i-1][1]);
    }
    if(min(solve[K][1],solve[K][0]) >= INF - 1) cout << -1;
    else cout << min(solve[K][1],solve[K][0]);
}