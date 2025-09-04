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

int SP[5050505]; // SP[i] = i의 가장 작은 소인수
vector<int> Primes;
 void Sieve(int n){
 for(int i=2; i<=n; i++){
 if(SP[i]) continue;
 for(int j=i; j<=n; j+=i) if(!SP[j]) SP[j] = i;
 }
 }
 // Sieve 먼저 호출해야 함
vector<pair<int,int>> Factorize(int n){
    vector<pair<int,int>> res;
    while(n != 1){
        if(res.empty() || res.back().first != SP[n]) res.emplace_back(SP[n], 1);
        else res.back().second++;
        n /= SP[n];
    }
    return res;
}

ll PowMod(ll a, ll b, ll c){
    if(c == 1) return 0;
    ll res = 1;
    for(a%=c; b; b >>= 1, a = a * a % c) if(b & 1) res = res * a % c;
    return res;
}
void press(){
    vector<int> C;
    for(int i=0; i<N; i++) C.push_back(A[i]);
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
    for(int i=0; i<N; i++){
        A[i] = lower_bound(C.begin(), C.end(), A[i])- C.begin();
    }
}

tuple<ll,ll,ll> ext_gcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    auto [g,x,y] = ext_gcd(b, a % b);
    return {g, y, x- a/b * y};
}

ll mod(ll a, ll b){ return (a %= b) >= 0 ? a : a + b; }
    pair<ll,ll> crt(ll a1, ll m1, ll a2, ll m2){
    ll g = gcd(m1, m2), m = m1 / g * m2;
    if((a2- a1) % g) return {-1,-1};
    ll md = m2/g, s = mod((a2-a1)/g, m2/g);
    ll t = mod(get<1>(ext_gcd(m1/g%md, m2/g)), md);
    return { a1 + s * t % md * m1, m };
}

vector<int> GetFail(const string &p){
    int n = p.size();
    vector<int> fail(n);
        for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}
vector<int> KMP(const string &s, const string &p){
    int n = s.size(), m = p.size();
    vector<int> fail = GetFail(p), ret;
    for(int i=0, j=0; i<s.size(); i++){
    while(j && s[i] != p[j]) j = fail[j-1];
    if(s[i] == p[j]){
    if(j + 1 == m) ret.push_back(i-m+1), j = fail[j];
    else j++;
    }
    }
    return ret;
}

constexpr int SZ = 10'000'000;
bool PrimeCheck[SZ+1]; 
vector<int> Primes;
void Sieve(){
    memset(PrimeCheck, true, sizeof PrimeCheck);
    PrimeCheck[0] = PrimeCheck[1] = false;
    for(int i=2; i<=SZ; i++){
    if(PrimeCheck[i]) Primes.push_back(i);
    for(auto j : Primes){
    if(i*j > SZ) break;
    PrimeCheck[i*j] = false;
    if(i % j == 0) break;
    }
    }
}
using ll = long long;
using ull = unsigned long long;
ull MulMod(ull a, ull b, ull c){ return (__uint128_t)a * b % c; }
ull PowMod(ull a, ull b, ull c){
ull res = 1; a %= c;
for(; b; b>>=1, a=MulMod(a,a,c)) if(b & 1) res = MulMod(res,a,c);
return res;
}
bool MillerRabin(ull n, ull a){
    if(a % n == 0) return true;
    int cnt = __builtin_ctzll(n- 1);
    ull p = PowMod(a, n >> cnt, n);
    if(p == 1 || p == n- 1) return true;
    while(cnt--) if((p=MulMod(p,p,n)) == n- 1) return true;
    return false;
}
bool IsPrime(ll n){
    if(n <= SZ) return PrimeCheck[n];
    if(n <= 2) return n == 2;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0) return false;
    for(int p : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) if(!MillerRabin(n, p))
    return false;
    return true;
}
ll Rho(ll n){
    while(true){
        ll x = rand() % (n- 2) + 2, y = x, c = rand() % (n- 1) + 1;
        while(true){
        x = (MulMod(x, x, n) + c) % n;
        y = (MulMod(y, y, n) + c) % n;
        y = (MulMod(y, y, n) + c) % n;
        ll d = __gcd(abs(x- y), n);
        if(d == 1) continue;
        if(IsPrime(d)) return d;
        else{ n = d; break; }
        }
    }
}
vector<pair<ll,ll>> Factorize(ll n){
    vector<pair<ll,ll>> v;
    int two = __builtin_ctzll(n);
    if(two > 0) v.emplace_back(2, two), n >>= two;
    if(n == 1) return v;
    while(!IsPrime(n)){
    ll d = Rho(n), cnt = 0;
    while(n % d == 0) cnt++, n /= d;
    v.emplace_back(d, cnt);
    if(n == 1) break;
    }
    if(n != 1) v.emplace_back(n, 1);
    return v;
}