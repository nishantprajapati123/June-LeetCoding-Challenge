// TIme complexity :- Time Complexity = (M*N for board traversal) * TimeComplexity(dfs) (O(MN(4 * 3^(L-1)))
// Space complexity :- Space for Trie (n*m) (n = length of words vector, m = length of each word)
class Solution {
    int dir1[4] = {-1, 1, 0, 0};
    int dir2[4] = {0, 0, -1, 1};
public:
    struct Trie
    {
        Trie* arr[26];
        // vector<Trie*>arr(26,NULL)
        string word;
        bool isWord;
        Trie()
        {
            word = "";
            isWord = false;
            for(int i=0;i<26;i++)
                arr[i] = nullptr;
        }
    };
    bool isSafe(vector<vector<char> >&board, int x, int y)
    {
        return (x>=0 && x < board.size() && y>=0 && y < board[0].size());
    }
    void insert(Trie *root, string str)
    {
        Trie *curr = root;
        for(int i=0;i<str.length();i++)
        {
            int index = str[i]-'a';
            if(curr->arr[index] == nullptr)
                curr->arr[index] = new Trie();
            curr = curr->arr[index];
        }
        curr->isWord = true;
        curr->word = str;
    }
    void dfs(vector<vector<char>>& board, int x, int y, Trie* curr, char ch, set<string>&res)
    {
        if(board[x][y] == '#' || curr->arr[ch-'a'] == NULL)  return;
        char next_ch = board[x][y];
        board[x][y] = '#';
        curr = curr->arr[next_ch-'a'];
        
        if(curr != nullptr && curr->isWord)
            res.insert(curr->word);
        
        for(int d=0;d<4;d++)
        {
            int new_x = dir1[d] + x;
            int new_y = dir2[d] + y;
            
            if(isSafe(board, new_x, new_y))
            {
                dfs(board, new_x, new_y, curr, board[new_x][new_y], res);
            }
        }
        board[x][y] = next_ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie *root = new Trie();
        set<string> res;
        for(string word: words)
        {
            insert(root, word);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(root->arr[board[i][j]-'a'] != nullptr)
                    dfs(board, i, j, root, board[i][j], res);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    
};