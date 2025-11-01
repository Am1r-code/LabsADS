#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        vector<int> common;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                common.push_back(a[i]);
                ++i;
                ++j;
            } else if (a[i] < b[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        for (int x : common)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
