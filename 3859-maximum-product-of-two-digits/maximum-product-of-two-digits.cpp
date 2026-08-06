class Solution {
public:
    int maxProduct(int n) {
        int firstDig = 0, secDig = 0;

        while (n > 0) {
            int lastDig = n % 10;

            if (lastDig >= firstDig) {
                secDig = firstDig;
                firstDig = lastDig;
            }
            else if (lastDig > secDig) {
                secDig = lastDig;
            }

            n /= 10;
        }

        return firstDig * secDig;
    }
};