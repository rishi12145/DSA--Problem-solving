class Solution {
public:

    struct Node {
        int product;
        long long pref[5];

        Node() {
            product = 1;

            for(int i = 0; i < 5; i++) {
                pref[i] = 0;
            }
        }
    };

    int k;
    vector<Node> tree;

    Node merge(Node left, Node right) {

        Node res;

        
        res.product = (left.product * right.product) % k;

        
        for(int r = 0; r < k; r++) {
            res.pref[r] += left.pref[r];
        }

        
        for(int r = 0; r < k; r++) {

            int newR = (left.product * r) % k;

            res.pref[newR] += right.pref[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if(l == r) {

            int value = nums[l] % k;

            tree[node].product = value;
            tree[node].pref[value] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, int value) {

        if(l == r) {

            value %= k;

            tree[node].product = value;

            for(int i = 0; i < k; i++) {
                tree[node].pref[i] = 0;
            }

            tree[node].pref[value] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if(index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

      
        if(ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;

        
        if(qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        
        if(ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

       
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> result;

        for(auto q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            
            Node curr = query(1, 0, n - 1, start, n - 1);

            result.push_back(curr.pref[x]);
        }

        return result;
    }
};