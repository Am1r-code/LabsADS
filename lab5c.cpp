#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    priority_queue<int> maxHeap;   
    for (int i = 0; i < n; ++i) {
        int seats;
        cin >> seats;
        maxHeap.push(seats);  
    }
    long long totalrevenue = 0;
    for (int i = 0; i < x; ++i) {
        int maxseats = maxHeap.top(); 
        maxHeap.pop();  
        totalrevenue += maxseats; 
        maxseats--;  
        maxHeap.push(maxseats);  
    }
    cout << totalrevenue << endl;    
    return 0;
}
