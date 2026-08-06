class Solution {
public:
    int digitProduct(int x) {
        int prod = 1;
        while (x > 0) {
            prod = prod * (x % 10);
            x = x / 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (digitProduct(n) % t == 0)
                return n;
            n++;
        }
    }
};