struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(26) {}
};

class Solution {
 public:
  string boldWords(vector<string>& words, string s) {
    const int n = s.length();
    string ans;
    // bold[i] := true if s[i] should be bolded
    vector<bool> bold(n);

    for (const string& word : words)
      insert(word);

    int boldEnd = -1;  // `s[i..boldEnd]` should be bolded.
    for (int i = 0; i < n; ++i) {
      boldEnd = max(boldEnd, find(s, i));
      bold[i] = boldEnd >= i;
    }

    // Construct the string with the bold tags.
    int i = 0;
    while (i < n)
      if (bold[i]) {
        int j = i;
        while (j < n && bold[j])
          ++j;
        // `s[i..j)` should be bolded.
        ans += "<b>" + s.substr(i, j - i) + "</b>";
        i = j;
      } else {
        ans += s[i++];
      }

    return ans;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
    }
    node->isWord = true;
  }

  int find(const string& s, int i) {
    shared_ptr<TrieNode> node = root;
    int ans = -1;
    for (int j = i; j < s.length(); ++j) {
      const int index = s[j] - 'a';
      if (node->children[index] == nullptr)
        return ans;
      node = node->children[index];
      if (node->isWord)
        ans = j;
    }
    return ans;
  }
};
