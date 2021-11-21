class Solution {
 public:
  int findTheLongestSubstring(string s) {
    int ans = 0;
    int prefix = 0;  // binary prefix
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < s.length(); ++i) {
      const int index = string("aeiou").find(s[i]);
      if (index != -1)
        prefix ^= 1 << index;
      if (!prefixToIndex.count(prefix))
        prefixToIndex[prefix] = i;
      ans = max(ans, i - prefixToIndex[prefix]);
    }

    return ans;
  }
};
