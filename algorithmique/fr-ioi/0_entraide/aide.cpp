#include <bits/stdc++.h>
using namespace std;
int main() {
    string pp; getline(cin,pp);
    int N; cin >> N;
    cin.ignore();
    for(int n=0;n<N;n++){
      string s; getline(cin, s);
      int M = 1;
      s[0]=toupper(s[0]);
      if (s[0] != pp[0]) {
          continue;
      }
      bool c = true;
      bool up= false;
      int len = (int)s.length();
      for(int i=1;i<len;i++){
         if (s[i]== ' ' && i+1<length && s[i+1]==pp[M]){
             M++;
            if (p == pp[M]){
               p = toupper(s[i+1]);
               up = true;
               M++;
            }else{
               c = false;
               break;
            }
         }
         else if(up){
            s[i]= toupper(s[i]);
            up = false;
         }
         else
            s[i]= tolower(s[i]);     
      }if(c && M+1 >= (int)pp.length()){
         cout << s << endl;
      }else
         continue;
   }      
    return 0;
}