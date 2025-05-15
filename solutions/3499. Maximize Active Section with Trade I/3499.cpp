#include <ranges>

class Solution {
 public:
  int maxActiveSectionsAfterTrade(string s) {
    vector<int> zeroGroupLengths;
    int maxZeroMerge = 0;

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '0') {
        if (i > 0 && s[i - 1] == '0')
          ++zeroGroupLengths.back();
        else
          zeroGroupLengths.push_back(1);
      }

    for (const auto& [a, b] : zeroGroupLengths | views::pairwise)
      maxZeroMerge = max(maxZeroMerge, a + b);

    return ranges::count(s, '1') + maxZeroMerge;
  }
};
