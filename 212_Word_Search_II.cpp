typedef struct Trie_s Trie_t;

typedef struct Trie_s {
    bool is_end;
    Trie_t *next[26];
} Trie_t;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie_t *root = new Trie_t;
        memset(root->next, 0, sizeof(root->next)); 
        root->is_end = false;
        for (string w : words) {
            Trie_t *node = root;
            for (char c : w) {
                if (node->next[c - 'a'] == nullptr) {
                    node->next[c - 'a'] = new Trie_t;
                    memset(node->next[c - 'a'], 0, sizeof(Trie_t)); 
                    node->next[c - 'a']->is_end = false;
                }

                node = node->next[c - 'a'];
            }
            node->is_end = true;
        }

        vector<string> answer;
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[x].size(); y++) {
                DFS_search(board, root, "", x, y, answer);
            }
        }

        return answer;
    }

private:
    

    void DFS_search(vector<vector<char>>& board, Trie_t *node, string curr_str, 
                    int x, int y, vector<string> &answer)
    {
        if (node->is_end == true) {
            answer.emplace_back(curr_str);
            node->is_end = false;
            return ;
        }
        
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size()
            || board[x][y] == '#')
        {
            return ;
        }

        char tmp = board[x][y];
        node = node->next[tmp - 'a'];
        if (node == nullptr)
            return ;

        curr_str += tmp;

        board[x][y] = '#';
        DFS_search(board, node, curr_str, x + 1, y, answer);
        DFS_search(board, node, curr_str, x - 1, y, answer);
        DFS_search(board, node, curr_str, x, y + 1, answer);
        DFS_search(board, node, curr_str, x, y - 1, answer);
        board[x][y] = tmp;
    }

};


// better version
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Trie
{
public:
    bool isEnd;
    Trie *nxt[26];
    string word;
    Trie()
    {
        isEnd = 0;
        for (int i = 0; i < 26; i++)
        {
            nxt[i] = nullptr;
        }
        word = "";
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char each : word)
        {
            if (node->nxt[each - 'a'] == nullptr)
            {
                node->nxt[each - 'a'] = new Trie();
            }
            node = node->nxt[each - 'a'];
        }
        node->isEnd = 1;
        node->word = word;
    }
};
class Solution
{
public:
    vector<string> ans;
    void dfs(Trie *now, int x, int y, vector<vector<char>> &board)
    {
        if (now->isEnd)
        {
            now->isEnd = 0;
            ans.push_back(now->word);
            return;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return;
        if (board[x][y] == '#')
            return;
        if (now->nxt[board[x][y] - 'a'] == nullptr)
            return;
        now = now->nxt[board[x][y] - 'a'];
        char cur = board[x][y];
        board[x][y] = '#';
        dfs(now, x + 1, y, board);
        dfs(now, x - 1, y, board);
        dfs(now, x, y + 1, board);
        dfs(now, x, y - 1, board);
        board[x][y] = cur;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *root = new Trie();
        for (auto word : words)
        {
            root->insert(word);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(root, i, j, board);
            }
        }
        return ans;
    }
};
