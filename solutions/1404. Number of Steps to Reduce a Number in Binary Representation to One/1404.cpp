class Solution {
 public:
  int numSteps(string s) {
    int ans = 0;

    // All the trailing 0s can be popped by 1 step.
    while (s.back() == '0') {
      s.pop_back();
      ++ans;
    }

    if (s == "1")
      return ans;

    // `s` is now odd, so add 1 to `s` and cost 1 step.
    ++ans;

    // All the 1s will become 0s and can be popped by 1 step.
    // All the 0s will become 1s and can be popped by 2 steps (adding 1 then
    // dividing by 2).
    for (const char c : s)
      ans += c == '1' ? 1 : 2;

    return ans;
  }
};
