import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // Read number of inputs
        long ans = 0; // Use long for large sums

        for (int i = 0; i < n; i++) {
            ans += Integer.parseInt(br.readLine()); // Read and sum integers
        }

        System.out.println(ans); // Output the result
    }
}
