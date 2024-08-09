class Solution {
 public:
  int punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      if (isPossible(0, 0, to_string(i * i), 0, i))
        ans += i * i;
    return ans;
  }

 private:
  // Returns true if the sum of any split of `numChars` equals to the target.
  bool isPossible(int accumulate, int running, const string& numChars, int s,
                  int target) {
    if (s == numChars.length())
      return target == accumulate + running;
    const int d = numChars[s] - '0';
    return isPossible(accumulate, running * 10 + d, numChars, s + 1, target) ||
           isPossible(accumulate + running, d, numChars, s + 1, target);
  }
};
