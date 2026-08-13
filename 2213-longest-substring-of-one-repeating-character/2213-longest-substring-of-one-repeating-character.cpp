class Solution {
public:
    struct Node {
        int size;
        char leftChar, rightChar;
        int prefLen, sufLen, best;
    };

    vector<Node> tree;
    string str;
    int n;

    Node merge(const Node& a, const Node& b) {
        Node res;
        res.size = a.size + b.size;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefLen = a.prefLen;
        if (a.prefLen == a.size && a.leftChar == b.leftChar) {
            res.prefLen += b.prefLen;
        }

        res.sufLen = b.sufLen;
        if (b.sufLen == b.size && a.rightChar == b.rightChar) {
            res.sufLen += a.sufLen;
        }

        res.best = max(a.best, b.best);
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.sufLen + b.prefLen);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, str[l], str[l], 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node] = {1, ch, ch, 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, ch);
        else update(2*node+1, mid+1, r, idx, ch);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        n = str.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);

        int k = queryCharacters.size();
        vector<int> result(k);

        for (int i = 0; i < k; i++) {
            char c = queryCharacters[i];
            int idx = queryIndices[i];
            str[idx] = c;
            update(1, 0, n - 1, idx, c);
            result[i] = tree[1].best;
        }

        return result;
    }
};