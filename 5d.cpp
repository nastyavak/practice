#include <iostream>
#include <string>
using namespace std;

const long long MOD = 1000000007;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();

    long long fact[100001];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }

    long long ans = fact[n];
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 1) {
            long long inv = power(fact[cnt[i]], MOD - 2);
            ans = (ans * inv) % MOD;
        }
    }
    cout << ans << "\n";
}