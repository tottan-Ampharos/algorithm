#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 以下をコピペ
const int SIEVE_MAX_N = 200'000'000;

int prime[SIEVE_MAX_N/2];
bool is_prime[SIEVE_MAX_N + 1];

int sieve(int n) {
    int cnt = 1;
    for (int i = 3; i < n; i+=2) is_prime[i] = true;
    prime[0] = 2;
    is_prime[2] = true;

    for (int i = 3; i <= n; i+=2) {
        if (is_prime[i]) {
            prime[cnt++] = i;
            for (int j = 2*i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return cnt;
}

/*
prime[cnt]でSIEVE_MAX_N直前の素数を表す

10^7まで現実的な速度で解ける
real    0m0.327s
user    0m0.281s
sys     0m0.021s
*/