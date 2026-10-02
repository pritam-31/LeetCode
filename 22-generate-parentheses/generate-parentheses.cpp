class Solution {
public:

    void backtrack(vector<string>& ans, string current, int openBra, int closeBra, int n) {
        // Base case
        if(current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if(openBra < n) {
            backtrack(ans, current + "(", openBra + 1, closeBra, n);
        }

        // Add closing bracket
        if(closeBra < openBra) {
            backtrack(ans, current + ")", openBra, closeBra + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        backtrack(ans, "", 0, 0, n);

        return ans;
    }
};