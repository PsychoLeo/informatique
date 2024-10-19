#include <unistd.h> // For read()
#include <cstdio>   // For write()

// Fast input function that handles both positive and negative integers
inline int fast_read_int() {
    int num = 0;
    char c;
    bool negative = false;
    
    // Fast input using getchar_unlocked()
    while ((c = getchar_unlocked()) != '-' && (c < '0' || c > '9')); // Skip non-numeric characters and check for '-'

    if (c == '-') {
        negative = true; // Mark as negative
        c = getchar_unlocked(); // Move to the next character
    }

    // Build the number
    do {
        num = num * 10 + (c - '0');
    } while ((c = getchar_unlocked()) >= '0' && c <= '9'); // Continue reading digits

    // If it was negative, apply the negative sign
    return negative ? -num : num;
}

// Fast output function to print integers
inline void fast_write_int(int num) {
    char buffer[7];
    int len = 0;

    if (num == 0) {
        putchar_unlocked('0');
        return;
    }

    if (num < 0) {
        putchar_unlocked('-'); // Output the negative sign
        num = -num; // Convert to positive for processing
    }

    // Convert number to string
    while (num > 0) {
        buffer[len++] = '0' + (num % 10);
        num /= 10;
    }

    // Output the characters in reverse order
    while (len--) {
        putchar_unlocked(buffer[len]);
    }
}

int main() {
    int n = fast_read_int(); // Fast read for number of integers
    int ans = 0;

    while (n--) {
        ans += fast_read_int(); // Fast read for each integer and sum them up
    }

    fast_write_int(ans); // Fast write for output
    putchar_unlocked('\n'); // Output newline
    return 0;
}
