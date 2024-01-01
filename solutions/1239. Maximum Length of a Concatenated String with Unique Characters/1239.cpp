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
  int dfs(const vector<int>& masks, int s, int usedMask) {
    int res = __builtin_popcount(usedMask);
    for (int i = s; i < masks.size(); ++i)
      if ((usedMask & masks[i]) == 0)
        res = max(res, dfs(masks, i + 1, usedMask | masks[i]));
    return res;
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
