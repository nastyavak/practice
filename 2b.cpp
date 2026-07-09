#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> q;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        q.push(x);
    }

    for (int i = 0; i < n - 1; i++) {
        long long a = q.top();
        q.pop();
        long long b = q.top();
        q.pop();

        cout << a << " " << b << "\n";
        q.push(a + b);
    }

    return 0;
}