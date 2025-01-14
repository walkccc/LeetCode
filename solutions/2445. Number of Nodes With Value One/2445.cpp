class Solution {
 public:
  int numberOfNodes(int n, vector<int>& queries) {
    // flipped[i] := true if we should flip all the values in the subtree rooted
    // at i
    vector<bool> flipped(n + 1);

    for (const int query : queries)
      flipped[query] = flipped[query] ^ true;

    return dfs(1, 0, n, flipped);
  }

 private:
  int dfs(int label, int value, int n, const vector<bool>& flipped) {
    if (label > n)
      return 0;
    value ^= flipped[label];
    return value +  //
           dfs(label * 2, value, n, flipped) +
           dfs(label * 2 + 1, value, n, flipped);
  }
};
