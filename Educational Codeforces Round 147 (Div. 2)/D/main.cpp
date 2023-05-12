#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, k, ans = -1, one = 0, two = 0, sum = 0;
        cin >> n >> k;
        vector<int> l(n), r(n);
        for (int &li : l) {
            cin >> li;
        }
        for (int &ri : r) {
            cin >> ri;
        }
        for (int i = 0; i < n; i += 1) {
            LL x = r[i] - l[i] + 1;
            if (sum + one + x >= k) {
                int pans = sum + x >= k
                               ? l[i] + k - sum - 1 + (two + 1) * 2
                               : r[i] + (k - sum - x) * 2 + (two + 1) * 2;
                if (ans == -1 or ans > pans) {
                    ans = pans;
                }
            }
            if (x == 1) {
                one += 1;
            } else {
                sum += x;
                two += 1;
            }
            if (sum >= k) {
                break;
            }
        }
        cout << ans << "\n";
    }
}
