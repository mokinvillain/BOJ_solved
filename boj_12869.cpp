#include<bits/stdc++.h>

using namespace std;

int N,A,B,C,DP[70][70][70];

int solve(int a,int b,int c){
    if(DP[a][b][c]) return DP[a][b][c];
    if(a == 0 && b == 0 && c == 0) return DP[0][0][0] = 0;
    DP[a][b][c] = INT_MAX;
    DP[a][b][c] = min(solve(max(a-9,0),max(b-3,0),max(c-1,0))+1,DP[a][b][c]);
    DP[a][b][c] = min(solve(max(a-9,0),max(b-1,0),max(c-3,0))+1,DP[a][b][c]);
    DP[a][b][c] = min(solve(max(a-3,0),max(b-9,0),max(c-1,0))+1,DP[a][b][c]);
    DP[a][b][c] = min(solve(max(a-1,0),max(b-9,0),max(c-3,0))+1,DP[a][b][c]);
    DP[a][b][c] = min(solve(max(a-1,0),max(b-3,0),max(c-9,0))+1,DP[a][b][c]);
    DP[a][b][c] = min(solve(max(a-3,0),max(b-1,0),max(c-9,0))+1,DP[a][b][c]);
    return DP[a][b][c];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    if(N == 1){
        cin >> A;
        cout << solve(A,0,0);
    }
    else if(N == 2){
        cin >> A >> B;
        cout << solve(A,B,0);
    }
    else{
        cin >> A >> B >> C;
        cout << solve(A,B,C);
    }
}