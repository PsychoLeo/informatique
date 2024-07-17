#include <iostream>  
#include <cstring>  
 
int magic (char *a)  
{  
 int res=(int)(a[strlen(a)]);  
 res|=res+1;  
 res<<=5;  
 res+=10;  
 return res;  
}  
 
using namespace std;  
 
int main(int argc, char *argv[]) {  
    cout << magic(argv[0]) << endl;  
    return 0;  
}