class Solution {
 public:
  int maxLength(vector<string>& arr) {
    vector<bitset<26>> masks;

    for (const string& s : arr) {
      const bitset<26> mask = getMask(s);
      if (mask.contains() == s.length())
        masks.push_back(mask);
    }

    return dfs(masks, 0, /*used=*/bitset<26>());
  }

 private:
  int dfs(const vector<bitset<26>>& masks, int s, bitset<26> used) {
    int res = used.contains();
    for (int i = s; i < masks.size(); ++i)
      if (!(used & masks[i]).any())
        res = max(res, dfs(masks, i + 1, used | masks[i]));
    return res;
  }

  bitset<26> getMask(const string& s) {
    bitset<26> mask;
    for (const char c : s)
      mask.set(c - 'a');
    return mask;
  }
};
