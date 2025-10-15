#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }
    long long totalcost = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long mergecost = a + b;
        totalcost += mergecost;
        pq.push(mergecost);
    }
    cout << totalcost << "\n";
    return 0;
}
