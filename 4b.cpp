#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long mx = a[i];
        for (int j = i; j < n; j++) {
            mx = max(mx, a[j]);
            sum += mx;
        }
    }
    cout << sum;
}