#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
struct Student {
    string last, first;
    double gpa;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, double> grade = {
        {"A+", 4.00}, {"A", 3.75},
        {"B+", 3.50}, {"B", 3.00},
        {"C+", 2.50}, {"C", 2.00},
        {"D+", 1.50}, {"D", 1.00},
        {"F", 0.00}
    };
    int n;
    if (!(cin >> n)) return 0;
    vector<Student> students;
    students.reserve(n);
    for (int i = 0; i < n; ++i) {
        string last, first;
        int m;
        cin >> last >> first >> m;
        double total_points = 0.0, total_credits = 0.0;
        for (int j = 0; j < m; ++j) {
            string mark;
            int credit;
            cin >> mark >> credit;
            total_points += grade[mark] * credit;
            total_credits += credit;
        }
        double gpa = (total_credits == 0.0) ? 0.0 : (total_points / total_credits);
        students.push_back({last, first, gpa});
    }
    const double EPS = 1e-9;
    sort(students.begin(), students.end(), [&](const Student &a, const Student &b) {
        if (fabs(a.gpa - b.gpa) > EPS) return a.gpa < b.gpa;
        if (a.last != b.last) return a.last < b.last;
        return a.first < b.first;
    });
    cout << fixed << setprecision(3);
    for (const auto &s : students) {
        cout << s.last << " " << s.first << " " << s.gpa << "\n";
    }
    return 0;
}