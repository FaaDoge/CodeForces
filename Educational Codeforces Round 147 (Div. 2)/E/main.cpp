#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }

        ll ans = 0, black_cells = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            if (black_cells >= k) break;
            if (prev >= l[i]) {
                black_cells += min(r[i] - prev, k - black_cells);
                prev = min(prev + min(r[i] - prev, k - black_cells), r[i]);
            } else {
                int dist = l[i] - prev;
                if (dist + black_cells < k) {
                    ans += dist;
                    black_cells += dist;
                    prev = l[i];
                } else {
                    ans += (k - black_cells);
                    black_cells = k;
                    prev += (k - black_cells);
                }
            }
        }
        if (black_cells < k) ans = -1;
        cout << ans << endl;
    }

    return 0;
}
