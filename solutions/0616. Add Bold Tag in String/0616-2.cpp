struct TrieNode {
  vector<TrieNode*> children;
  bool isWord = false;
  TrieNode() : children(128) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Solution {
 public:
  string addBoldTag(string s, vector<string>& words) {
    const int n = s.length();
    string ans;
    // bold[i] := true if s[i] should be bolded
    vector<bool> bold(n);

    for (const auto& word : words)
      insert(word);

    int boldEnd = -1;  // s[i..boldEnd] should be bolded
    for (int i = 0; i < n; ++i) {
      boldEnd = max(boldEnd, find(s, i));
      bold[i] = boldEnd >= i;
    }

    // construct the string with bold tags
    int i = 0;
    while (i < n)
      if (bold[i]) {
        int j = i;
        while (j < n && bold[j])
          ++j;
        // s[i:j] should be bolded
        ans += "<b>" + s.substr(i, j - i) + "</b>";
        i = j;
      } else {
        ans += s[i++];
      }

    return ans;
  }

 private:
  TrieNode root;

  void insert(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      if (!node->children[c])
        node->children[c] = new TrieNode;
      node = node->children[c];
    }
    node->isWord = true;
  }

  int find(const string& s, int i) {
    TrieNode* node = &root;
    int ans = -1;
    for (int j = i; j < s.length(); ++j) {
      if (!node->children[s[j]])
        return ans;
      node = node->children[s[j]];
      if (node->isWord)
        ans = j;
    }
    return ans;
  }
};
