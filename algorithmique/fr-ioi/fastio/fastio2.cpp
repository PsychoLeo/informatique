#include <unistd.h>

const int BUFFER_SIZE = 64 << 20; // 2 MB buffer for bulk reading
char input_buffer[BUFFER_SIZE];  // Large input buffer
char output_buffer[12];          // Buffer for output (large enough for a 32-bit int)

inline int fast_read_int() {
    static char* ptr = input_buffer;
    static char* end = input_buffer;

    // Refill the buffer if empty
    if (ptr == end) {
        int bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
        if (bytes_read <= 0) return 0; // EOF or error
        ptr = input_buffer;
        end = input_buffer + bytes_read;
    }

    // Parse the integer directly
    int num = 0;
    bool negative = false;

    // Skip non-digit characters and detect negative sign
    while (*ptr < '0' || *ptr > '9') {
        if (*ptr == '-') negative = true;
        if (++ptr == end) {
            int bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            if (bytes_read <= 0) return 0; // EOF or error
            ptr = input_buffer;
            end = input_buffer + bytes_read;
        }
    }

    // Build the number as fast as possible
    while (*ptr >= '0' && *ptr <= '9') {
        num = num * 10 + (*ptr - '0');
        if (++ptr == end) {
            int bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            if (bytes_read <= 0) break; // EOF or error
            ptr = input_buffer;
            end = input_buffer + bytes_read;
        }
    }

    return negative ? -num : num;
}

// Output function optimized to remove all overhead
inline void fast_write_int(int num) {
    char* p = output_buffer + 11; // Point to the end of the buffer
    *p = '\n';                    // Always end with a newline

    if (num == 0) {
        *--p = '0'; // Handle zero case
    } else {
        bool is_negative = false;
        if (num < 0) {
            is_negative = true;
            num = -num; // Convert to positive
        }

        // Write the digits in reverse order
        while (num > 0) {
            *--p = '0' + (num % 10);
            num /= 10;
        }

        // Add minus sign if necessary
        if (is_negative) {
            *--p = '-';
        }
    }

    // Write the buffer from 'p' to the end
    write(STDOUT_FILENO, p, output_buffer + 12 - p);
}

int main() {
    int n = fast_read_int(); // Read the number of integers
    int ans = 0;

    // Sum all the integers as fast as possible
    while (n--) {
        ans += fast_read_int();
    }

    fast_write_int(ans); // Output the result
    return 0;
}
