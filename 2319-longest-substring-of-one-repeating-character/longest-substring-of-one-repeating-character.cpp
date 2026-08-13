class Solution {
public:
    struct Node {
        int len;
        int left, right, best;
        char lc, rc;

        Node() {
            len = left = right = best = 0;
            lc = rc = '#';
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        // Initially, best is maximum of the two children
        res.best = max(a.best, b.best);

        // Prefix run
        res.left = a.left;
        if (a.left == a.len && a.rc == b.lc) {
            res.left = a.len + b.left;
        }

        // Suffix run
        res.right = b.right;
        if (b.right == b.len && a.rc == b.lc) {
            res.right = b.len + a.right;
        }

        // Run crossing the middle
        if (a.rc == b.lc) {
            res.best = max(res.best, a.right + b.left);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].left = 1;
            tree[node].right = 1;
            tree[node].best = 1;
            tree[node].lc = s[l];
            tree[node].rc = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            s[idx] = c;

            tree[node].len = 1;
            tree[node].left = 1;
            tree[node].right = 1;
            tree[node].best = 1;
            tree[node].lc = c;
            tree[node].rc = c;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();
        int k = queryIndices.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            // Root contains the answer for the whole string
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};