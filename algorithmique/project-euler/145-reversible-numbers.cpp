#include <iostream>
#include <string>

using namespace std;

#define MAX (int)1e9+1

int main() {
    long long ans = 0;
    for (int i=0; i<MAX; ++i) {
        if (i % 10) {
            int som = i;
            string s = to_string(i);
            reverse(s.begin(), s.end());
            som += stoi(s);
            while (som) {
                if (som % 2) som /= 10;
                else break; 
            }
            if (som == 0) {
                // cout << i << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}