#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<char, int> pci;

int m; // 초기 그룹의 개수
vector<pci> s;
ll dp[101][101][101];

ll solve(int i, int j, int k) {
    // 기저 사례: 구간이 비었으면 0점
    if (i > j) {
        return 0;
    }
    // 기저 사례: 그룹이 하나 남은 경우
    if (i == j) {
        if (s[i].second + k >= 2) {
            return (ll)(s[i].second + k) * (s[i].second + k);
        }
        return -1e15; // 불가능한 경우 (매우 작은 값)
    }

    // 메모이제이션
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    ll res = -1e15;

    // 방법 1: j번째 그룹을 마지막에 터뜨린다.
    if (s[j].second + k >= 2) {
        ll score1 = solve(i, j - 1, 0);
        if (score1 > -1e14) { // solve(i, j-1, 0)이 가능한 경우
            res = max(res, score1 + (ll)(s[j].second + k) * (s[j].second + k));
        }
    }

    // 방법 2: j번째 그룹을 p번째 그룹과 합쳐서 터뜨린다.
    for (int p = i; p < j; ++p) {
        if (s[p].first == s[j].first) {
            ll score_inner = solve(p + 1, j - 1, 0);
            if (score_inner > -1e14) { // 안쪽 구간을 모두 없애는게 가능한 경우
                ll score_outer = solve(i, p, s[j].second + k);
                if (score_outer > -1e14) {
                    res = max(res, score_inner + score_outer);
                }
            }
        }
    }

    return dp[i][j][k] = res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string str;
    cin >> str;

    if (str.length() < 2) {
        cout << 0 << endl;
        return 0;
    }

    // 초기 그룹 생성
    s.push_back({str[0], 1});
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == s.back().first) {
            s.back().second++;
        } else {
            s.push_back({str[i], 1});
        }
    }
    m = s.size();

    // DP 테이블 초기화
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k <= str.length(); ++k) {
                dp[i][j][k] = -1;
            }
        }
    }

    ll ans = solve(0, m - 1, 0);

    if (ans < 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
