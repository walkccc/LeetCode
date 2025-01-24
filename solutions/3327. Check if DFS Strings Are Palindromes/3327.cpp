class Solution {
 public:
  vector<bool> findAnswer(vector<int>& parent, string s) {
    const int n = parent.size();
    vector<bool> ans(n);
    vector<vector<int>> tree(n);
    vector<int> start(n);  // start[i] := the start index of `dfsStr` of node i
    vector<int> end(n);    // end[i] := the end index of `dfsStr` of node i
    string dfsStr;

    for (int i = 1; i < n; ++i)
      tree[parent[i]].push_back(i);

    dfs(tree, 0, /*index=*/0, s, start, end, dfsStr);
    const string t = join('@' + dfsStr + '$', /*delimiter=*/'#');
    const vector<int> p = manacher(t);

    for (int i = 0; i < n; ++i)
      ans[i] = isPalindrome(start[i], end[i], p);

    return ans;
  }

 private:
  // Returns the start index of the "DFS string" of u's next node.
  int dfs(const vector<vector<int>>& tree, int u, int index, const string& s,
          vector<int>& start, vector<int>& end, string& dfsStr) {
    start[u] = index;
    for (const int v : tree[u])
      index = dfs(tree, v, index, s, start, end, dfsStr);
    end[u] = index;
    dfsStr += s[u];
    return index + 1;
  }

  // Returns an array `p` s.t. `p[i]` is the length of the longest palindrome
  // centered at `t[i]`, where `t` is a string with delimiters and sentinels.
  vector<int> manacher(const string& t) {
    vector<int> p(t.length());
    int center = 0;
    for (int i = 1; i < t.length() - 1; ++i) {
      const int rightBoundary = center + p[center];
      const int mirrorIndex = center - (i - center);
      if (rightBoundary > i)
        p[i] = min(rightBoundary - i, p[mirrorIndex]);
      // Try to expand the palindrome centered at i.
      while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
        ++p[i];
      // If a palindrome centered at i expands past `rightBoundary`, adjust
      // the center based on the expanded palindrome.
      if (i + p[i] > rightBoundary)
        center = i;
    }
    return p;
  }

  // Returns true if `dfsStr[s..e]` is a palindrome by using the precomputed
  // array `p` from the Manacher's algorithm.
  //
  // The precomputed array `p` is based on the string `t` with delimiters and
  // sentinels. Let `t = '#'.join('@' + dfsStr + '$')`. Then, the center of
  // `dfsStr` maps to `t[s + e + 2]` since `dfsStr[s]` maps to `t[2 * s + 2]`
  // and `dfsStr[e]` maps to `t[2 * e + 2]`. So, the center of `dfsStr` is
  // `t[(2 * s + 2 + 2 * e + 2) / 2] = t[s + e + 2]`.
  bool isPalindrome(int s, int e, const vector<int>& p) {
    const int length = e - s + 1;
    const int center = s + e + 2;
    return p[center] >= length;
  }

  string join(const string& s, char delimiter) {
    string joined;
    for (int i = 0; i < s.length() - 1; ++i) {
      joined += s[i];
      joined += delimiter;
    }
    joined += s.back();
    return joined;
  }
};
