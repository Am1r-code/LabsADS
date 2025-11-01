#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector<int> merged;
    merged.reserve(n + m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i]);
            ++i;
        } else {
            merged.push_back(b[j]);
            ++j;
        }
    }
    while (i < n) merged.push_back(a[i++]);
    while (j < m) merged.push_back(b[j++]);
    for (int x : merged)
        cout << x << " ";
    cout << "\n";
    return 0;
}
