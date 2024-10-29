#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int n, max = 1000*1000*1000; 
	scanf("%d", &n);
	int l[n];
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		if ((l[i] % 3 == 0)&&(l[i] < max)) {
			max = l[i];
		}
	}
	printf("%d\n", max);
}