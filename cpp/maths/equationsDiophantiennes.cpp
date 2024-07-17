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

bool isAlwaysDivPythagTriplet (int d) {
	// Returns true if at least one of the terms of a 
	// Pytagorean triplet is always divisible by d
	int pq[d][d] = {};
	int p2pq2[d][d] = {};
	int p2mq2[d][d] = {};
	// printf("%d\n", (-1)%10);
	fo(i, d) {
		fo(j, d) {
			pq[i][j] = (2*i*j)%d;
			p2pq2[i][j] = (i*i+j*j)%d;
			p2mq2[i][j] = (i*i-j*j)%d;
			if (pq[i][j] != 0 && p2pq2[i][j] != 0 && p2mq2[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int x: {3, 5, 7}) {
		if (isAlwaysDivPythagTriplet(x)) {
			printf("%d|x ou %d|y ou %d|z\n", x, x, x);
		}
	}
	return 0;
}
