class Solution {
 public:
  long long countPalindromePaths(vector<int>& parent, string s) {
    // A valid (u, v) has at most 1 letter with odd frequency on its path. The
    // frequency of a letter on the u-v path is equal to the sum of its
    // frequencies on the root-u and root-v paths substract twice of its
    // frequency on the root-LCA(u, v) path. Considering only the parity
    // (even/odd), the part involving root-LCA(u, v) can be ignored, making it
    // possible to calculate both parts easily using a simple DFS.
    vector<vector<int>> tree(parent.size());

    for (int i = 1; i < parent.size(); ++i)
      tree[parent[i]].push_back(i);

    return dfs(tree, 0, 0, s, {{0, 1}});
  }

 private:
  // mask := 26 bits that represent the parity of each character in the alphabet
  // on the path from node 0 to node u
  long long dfs(const vector<vector<int>>& tree, int u, int mask,
                const string& s, unordered_map<int, int>&& maskToCount) {
    long long res = 0;
    if (u > 0) {
      mask ^= 1 << (s[u] - 'a');
      // Consider any u-v path with 1 bit set.
      for (int i = 0; i < 26; ++i)
        if (const auto it = maskToCount.find(mask ^ (1 << i));
            it != maskToCount.cend())
          res += it->second;
      // Consider u-v path with 0 bit set.
      res += maskToCount[mask ^ 0]++;
    }
    for (const int v : tree[u])
      res += dfs(tree, v, mask, s, move(maskToCount));
    return res;
  }
};
