#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 2097152 // 2 MB buffer

char input_buffer[BUFFER_SIZE]; // Input buffer

// Fast input function to read integers
int fast_read_int() {
    static char *ptr = input_buffer;
    static char *end = input_buffer;

    if (ptr == end) {
        int bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
        if (bytes_read <= 0) return 0; // EOF or error
        ptr = input_buffer;
        end = input_buffer + bytes_read;
    }

    int num = 0;
    int negative = 0;

    // Skip non-digit characters
    while (*ptr < '0' || *ptr > '9') {
        if (*ptr == '-') negative = 1;
        ptr++;
        if (ptr == end) {
            int bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            if (bytes_read <= 0) return 0; // EOF or error
            ptr = input_buffer;
            end = input_buffer + bytes_read;
        }
    }

    // Parse the integer
    while (*ptr >= '0' && *ptr <= '9') {
        num = num * 10 + (*ptr - '0');
        ptr++;
        if (ptr == end) {
            int bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            if (bytes_read <= 0) break; // EOF or error
            ptr = input_buffer;
            end = input_buffer + bytes_read;
        }
    }

    return negative ? -num : num;
}

int main() {
    int n = fast_read_int(); // Read the number of inputs
    long long ans = 0; // Use long long for large sums

    while (n--) {
        ans += fast_read_int();
    }

    printf("%lld\n", ans); // Output the result
    return 0;
}
