class Solution {
 public:
  int maxProduct(vector<string>& words) {
    size_t ans = 0;
    vector<int> masks;

    for (const string& word : words)
      masks.push_back(getMask(word));

    for (int i = 0; i < words.size(); ++i)
      for (int j = 0; j < i; ++j)
        if ((masks[i] & masks[j]) == 0)
          ans = max(ans, words[i].length() * words[j].length());

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
