#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    Node* links[26];
    bool isEnd;
 
    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
        isEnd = false;
    }
 
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
 
    Node* get(char ch) {
        return links[ch - 'a'];
    }
 
    void put(char ch) {
        links[ch - 'a'] = new Node();
    }
};
 
struct Trie {
    Node* root = NULL;
 
    Trie() {
        root = new Node();
    }
 
    void insert(string str) {
        Node* node = root;
        for (auto ch : str) {
            if (!node->contains(ch)) {
                node->put(ch);
            }
            node = node->get(ch);
        }
        node->isEnd = true;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    string str;
    cin >> str;
 
    int n = str.length();
 
    int k;
    cin >> k;
 
    vector<string> words(k);
    for (int i = 0; i < k; i++) cin >> words[i];
 
    Trie trie;
    for (auto str: words) {
        trie.insert(str);
    }
 
    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
 
    for (int i = 0; i < n; i++) {
        Node* node = trie.root;
        for (int j = i + 1; j <= n; j++) {
            char c = str[j - 1];
            if (!node->contains(c)) break;
 
            node = node->get(c);
            if (node->isEnd) {
                dp[j] += dp[i];
                if (dp[j] >= MOD) dp[j] -= MOD;
            }
        }
    }
 
    cout << dp[n] << endl;
    
    return 0;
}
