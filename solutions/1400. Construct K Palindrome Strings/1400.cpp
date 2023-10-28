class Solution {
 public:
  bool canConstruct(string s, int k) {
    // If the s.length() < k, we cannot construct k strings from s.
    if (s.length() < k)
      return false;

    bitset<26> odd;

    for (const char c : s)
      odd.flip(c - 'a');

    // If the # of characters that have odd counts is > k, the min # of
    // palindrome strings we can construct is > k.
    return odd.count() <= k;
  }
};
