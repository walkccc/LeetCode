class Solution {
 public:
  int maxLength(vector<string>& arr) {
    vector<bitset<26>> masks;

    for (const string& s : arr) {
      const bitset<26> mask = getMask(s);
      if (mask.count() == s.length())
        masks.push_back(mask);
    }

    return dfs(masks, 0, /*usedMask=*/bitset<26>());
  }

 private:
  int dfs(const vector<bitset<26>>& masks, int s, bitset<26> usedMask) {
    int res = usedMask.count();
    for (int i = s; i < masks.size(); ++i)
      if (!(usedMask & masks[i]).any())
        res = max(res, dfs(masks, i + 1, usedMask | masks[i]));
    return res;
  }

  bitset<26> getMask(const string& s) {
    bitset<26> mask;
    for (const char c : s)
      mask.set(c - 'a');
    return mask;
  }
};
