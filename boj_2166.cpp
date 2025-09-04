#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using Point = pair<ll, ll>;
Point operator + (Point p1, Point p2){ return {p1.x + p2.x, p1.y + p2.y}; }
Point operator- (Point p1, Point p2){ return {p1.x- p2.x, p1.y- p2.y}; }
ll operator * (Point p1, Point p2){ return p1.x * p2.x + p1.y * p2.y; } // 내적
ll operator / (Point p1, Point p2){ return p1.x * p2.y- p2.x * p1.y; } // 외적
int Sign(ll v){ return (v > 0)- (v < 0); } // 양수면 +1, 음수면-1, 0이면 0 반환
ll Dist(Point p1, Point p2){ return (p2- p1) * (p2- p1); } // 두 점 거리 제곱
ll SignedArea(Point p1, Point p2, Point p3){ return (p2- p1) / (p3- p1); }
int CCW(Point p1, Point p2, Point p3){ return Sign(SignedArea(p1, p2, p3)); }

ll N,ans,arr[10];
Point cv[10];
bool check[10];
vector<int> v;

void solve(int n){
    if(n == 8){
        cv[0] = {0,v[0]};
        cv[1] = {-v[1]/2,v[1]/2};
        cv[2] = {-v[2],0};
        cv[3] = {-v[3]/2,-v[3]/2};
        cv[4] = {0,-v[4]};
        cv[5] = {v[5]/2,-v[5]/2};
        cv[6] = {v[6],0};
        cv[7] = {v[7]/2,v[7]/2};
        for(int i = 0;i<8;i++){
            if(CCW(cv[i%8],cv[(i+1)%8],cv[(i+2)%8]) == -1) return;
        }
        ans++;
        return;
    }
    for(int i = 0;i<8;i++){
        if(!check[i]){
            check[i] = 1;
            v.push_back(arr[i]);
            solve(n+1);
            check[i] = 0;
            v.pop_back();
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    for(int i = 0;i<8;i++) cin >> arr[i];
    for(int i = 0;i<8;i++) arr[i] *= arr[i]*2;
    solve(0);
    cout << ans;
}