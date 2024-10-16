class Solution {
 public:
  int findTheLongestSubstring(string s) {
    constexpr string_view kVowels = "aeiou";
    int ans = 0;
    int prefix = 0;  // the binary prefix
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < s.length(); ++i) {
      const int index = kVowels.find(s[i]);
      if (index != -1)
        prefix ^= 1 << index;
      if (!prefixToIndex.contains(prefix))
        prefixToIndex[prefix] = i;
      ans = max(ans, i - prefixToIndex[prefix]);
    }

    return ans;
  }
};
