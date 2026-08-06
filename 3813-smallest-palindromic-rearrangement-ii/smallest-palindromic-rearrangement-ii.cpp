class Solution {
public:
    const long long LIM = 1e6;

    long long ways(vector<int>& c) {
        long long ans = 1;
        int used = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= c[i]; j++) {
                ans = ans * (used + j) / j;
                ans = min(ans, LIM);
            }
            used += c[i];
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> f(26), h(26);
        string mid, left;

        for (char x : s) f[x - 'a']++;

        for (int i = 0; i < 26; i++) {
            h[i] = f[i] / 2;
            if (f[i] & 1) mid += char('a' + i);
        }

        if (ways(h) < k) return "";

        for (int i = 0; i < s.size() / 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (!h[j]) continue;
                h[j]--;
                long long w = ways(h);
                if (w >= k) {
                    left += char('a' + j);
                    break;
                }
                k -= w;
                h[j]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};