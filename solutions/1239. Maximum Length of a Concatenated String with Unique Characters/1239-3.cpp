class Solution {
 public:
  int maxLength(vector<string>& arr) {
    vector<unsigned> masks;

    for (const string& s : arr) {
      const int mask = getMask(s);
      if (mask != -1)
        masks.push_back(mask);
    }

    return dfs(masks, 0, /*used=*/0);
  }

 private:
  int dfs(const vector<unsigned>& masks, int i, int used) {
    if (i == masks.size())
      return 0;
    const int pick =
        (masks[i] & used) == 0
            ? popcount(masks[i]) + dfs(masks, i + 1, used | masks[i])
            : 0;
    const int skip = dfs(masks, i + 1, used);
    return max(pick, skip);
  }

  int getMask(const string& s) {
    int mask = 0;
    for (const char c : s) {
      const int i = c - 'a';
      if ((mask & (1 << i)) != 0)
        return -1;
      mask |= 1 << i;
    }
    return mask;
  }
};
