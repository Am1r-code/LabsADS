#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<long long> pq; 
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() > 1) {
        long long y = pq.top(); pq.pop(); 
        long long x = pq.top(); pq.pop(); 

        if (x != y) {
            pq.push(y - x); 
        }
    }
    if (!pq.empty())
        cout << pq.top() << "\n";  
    else
        cout << 0 << "\n";   

    return 0;
}