class Solution {
 public:
  int numSub(string s) {
    constexpr int kMod = 1'000'000'007;

    int ans = 0;
    int l = -1;

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '0')
        l = i;  // Handle the reset value.
      ans = (ans + i - l) % kMod;
    }

    return ans;
  }
};
