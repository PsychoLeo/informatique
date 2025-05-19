/*
* Author:  Léopold Bernard
* Created: 23/04/2025 16:30:14
*/

#include <string>

const int MOD = 1000000007;
const int p = 31;
const int ip = 129032259;

typedef long long ll;

class Solution {
	public:
		int strStr(string s, string t) {
			int n = s.length();
			int m = t.length();
			ll ht = 0, h = 0; // h is hash of s, ht is hash of t
			if (m > n) return -1;
			ll powp = 1;
			for (int i=0; i<m; ++i) {
				h += (s[i]-'a'+1) * powp;
				ht += (t[i]-'a'+1) * powp;
				powp = (powp * p) % MOD;
				h %= MOD; ht %= MOD;
			}
			powp = (powp * ip) % MOD;
			if (h == ht) return 0;
			for (int i=0; i<n-m; ++i) {
				h = (h - (s[i]-'a'+1) + MOD) % MOD;
				h = (h * ip) % MOD;
				h = (h + (s[i+m]-'a'+1) * powp) % MOD;
				if (h == ht) return i+1;
			}
			return -1;
		}
};

int main() {
	return 0;
}
