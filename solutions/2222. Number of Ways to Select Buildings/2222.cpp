class Solution {
 public:
  long long numberOfWays(string s) {
    long ans = 0;
    // before[i] := the number of i before the current digit
    vector<int> before(2);
    // after[i] := the number of i after the current digit
    vector<int> after(2);
    after[0] = ranges::count(s, '0');
    after[1] = s.length() - after[0];

    for (const char c : s) {
      const int num = c - '0';
      --after[num];
      if (num == 0)
        ans += before[1] * after[1];
      else
        ans += before[0] * after[0];
      ++before[num];
    }

    return ans;
  }
};
