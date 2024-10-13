#include <bits/stdc++.h>
#define F(i,k,n) for(int i=k, i<n, i++)

using namespace std;

int main() {
    int t; cin>>t;
    while (t--) {
        int n,k; cin>>n>>k;
        vector<int> l,r;
        for (int i=0; i<n; i++) {
            int x; cin>>x;
            l.push_back(x);
        }
        for (int i=0; i<n; i++) {
            int x; cin>>x;
            r.push_back(x);
        }

        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        vector<int> lp,ls,rp,rs;
        int i=0;
        while (i<n) {
            if (i<n-1 && l[i]==l[i+1]) {
                lp.push_back(l[i]);
                i+=2;
            }
            else {
                ls.push_back(l[i]);
                i++;
            }
        }
        i=0;
        while (i<n) {
            if (i<n-1 && r[i]==r[i+1]) {
                rp.push_back(r[i]);
                i+=2;
            }
            else {
                rs.push_back(r[i]);
                i++;
            }
        }
        l.clear(); r.clear();
        for (int i=0; i<lp.size(); i++) {
            if (l.size()==2*k) break;
            l.push_back(lp[i]); l.push_back(lp[i]);
            r.push_back(rp[i]); r.push_back(rp[i]);
        }
        for (int i=0; i<ls.size(); i++) {
            if (l.size()==2*k) break;
            l.push_back(ls[i]);
            r.push_back(ls[i]);
        }
        for (int x: l) cout << x << " ";
        cout << '\n';
        for (int x: r) cout << x << " ";
        cout << '\n';

    }
}