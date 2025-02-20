class Solution {
 public:
  char findTheDifference(string s, string t) {
    const char sXors = accumulate(s.begin(), s.end(), 0, bit_xor<>());
    const char tXors = accumulate(t.begin(), t.end(), 0, bit_xor<>());
    return sXors ^ tXors;
  }
};
