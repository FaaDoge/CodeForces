#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 300005;

int n, m, k, dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {

        int sum = (i >= k) ? dp[i-k] : 0;
        dp[i] = (dp[i-1] + sum) % MOD;
        if (i-k >= 0) dp[i] = (dp[i] - dp[i-k] + MOD) % MOD;
    }

    int ans = dp[n] - dp[n-1];
    if (ans < 0) ans += MOD;

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        ans -= dp[x] - dp[x-1];
        if (ans < 0) ans += MOD;
    }

    cout << ans << '\n';

    return 0;
}
