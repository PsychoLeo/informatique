// Including
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <bitset>
#include <climits>

using namespace std;

// STL functions
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define f first
#define s second

// Iteration
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fo(i,n) for(int i=0; i<n; i++)

// Input and output
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x) 
#define ss(x) getline(cin, x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(x) cout << x << "\n"

// Types 
#define ll long long
#define ld long double
#define str string
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;

// Debugging
#define isDebug true
#ifdef isDebug
#define debug(x) cout << #x << "=" << x << "\n"
#else
#define debug(x)
#endif

#define inf 1000*1000*1000
#define MAX 1000*1000
vl primes;
bool P[MAX];

void fillPrimes() {
	fill(P, P+MAX, false);
	for (ll i=2; i<MAX; i++) {
		if (P[i]) {
			primes.pb(i);
			for (ll j=i*i; j<MAX; j+=i) {
				P[j] = false;
			}
		}
	}
}

ll pow8(ll x) {
	x = x*x;
	x = x*x;
	x = x*x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll pgcd = __gcd(pow8(7)-1, pow8(11)-1);
	for (ll i=6; pow8(i)<LLONG_MAX/2; i++) {
		if (P[i]) {
			pgcd = __gcd(pgcd, pow8(i)-1);
		}
		// debug(i);
	}
	pl(pgcd);
	return 0;
}