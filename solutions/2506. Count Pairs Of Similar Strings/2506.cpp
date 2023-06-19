class Solution {
 public:
  int similarPairs(vector<string>& words) {
    int ans = 0;
    vector<int> masks;

    for (const string& word : words)
      masks.push_back(getMask(word));

    for (int i = 0; i < masks.size(); ++i)
      for (int j = i + 1; j < masks.size(); ++j)
        if (masks[i] == masks[j])
          ++ans;

    return ans;
  }

 private:
  int getMask(const string& word) {
    int mask = 0;
    for (const char c : word)
      mask |= 1 << c - 'a';
    return mask;
  }
};
