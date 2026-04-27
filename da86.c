#include <stdio.h>

int main() {
    long long n;
    
    // Read input using scanf. It returns 1 if it successfully reads one item.
    if (scanf("%lld", &n) == 1) {
        // Base cases for 0 and 1
        if (n == 0 || n == 1) {
            printf("%lld\n", n);
            return 0;
        }
        
        long long left = 1;
        long long right = n;
        long long ans = 0;
        
        // Binary Search
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            // Using division to avoid integer overflow (mid <= n / mid)
            if (mid <= n / mid) {
                ans = mid;        // mid is a potential answer
                left = mid + 1;   // search for a larger integer in the right half
            } else {
                right = mid - 1;  // mid is too large, search in the left half
            }
        }
        
        // Output the result using printf
        printf("%lld\n", ans);
    }
    
    return 0;
}
