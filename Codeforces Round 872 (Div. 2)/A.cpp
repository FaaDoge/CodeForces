#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
 
void solve() {
    string s; cin >> s;
    if (*max_element(s.begin(), s.end()) == *min_element(s.begin(), s.end())) {
        cout << -1 << "\n";
    } else {
        cout << s.size() - 1 << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}