class Solution {
public:

    struct Node {
        Node* child[26];
        string word;

        Node() {
            word = "";

            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    vector<string> ans;

    void insert(Node* root, string word) {

        Node* curr = root;

        for(char ch : word) {

            int index = ch - 'a';

            if(curr->child[index] == NULL) {
                curr->child[index] = new Node();
            }

            curr = curr->child[index];
        }

        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node) {

        int m = board.size();
        int n = board[0].size();

       
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if(board[i][j] == '#') {
            return;
        }

        char ch = board[i][j];

        int index = ch - 'a';

        
        if(node->child[index] == NULL) {
            return;
        }

        Node* next = node->child[index];

        if(next->word != "") {
            ans.push_back(next->word);

            next->word = "";
        }

       
        board[i][j] = '#';

       
        dfs(board, i - 1, j, next);

        
        dfs(board, i + 1, j, next);

        dfs(board, i, j - 1, next);

        
        dfs(board, i, j + 1, next);

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Node* root = new Node();

        
        for(string word : words) {
            insert(root, word);
        }

        int m = board.size();
        int n = board[0].size();

      
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};