#include <stdio.h>
#include <string>

using namespace std;

class Book {
    public :
        int pages;
        string title;
        string author;
    
    void initBook (int p, string t, string a) {
        pages = p;
        title = t;
        author = a;
    }
};

int main() {
    Book b;
    b.initBook(100, "Kib", "Jouj");
    printf("%d\n", b.pages);
    return 0;
}