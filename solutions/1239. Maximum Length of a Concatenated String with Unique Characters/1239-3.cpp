class Solution {
 public:
  int maxLength(vector<string>& arr) {
    vector<int> masks;

    for (const string& s : arr) {
      const int mask = getMask(s);
      if (mask != -1)
        masks.push_back(mask);
    }

    return dfs(masks, 0, /*usedMask=*/0);
  }

 private:
  int dfs(const vector<int>& masks, int i, int usedMask) {
    if (i == masks.size())
      return 0;
    const int pick = (masks[i] & usedMask) == 0
                         ? __builtin_popcount(masks[i]) +
                               dfs(masks, i + 1, usedMask | masks[i])
                         : 0;
    const int skip = dfs(masks, i + 1, usedMask);
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
