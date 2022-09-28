class Solution {
 public:
  long long numberOfWays(string s) {
    long long ans = 0;
    // before[i] := # of i before current char
    vector<int> before(2);
    // after[i] := # of i after current char
    vector<int> after(2);
    after[0] = count(begin(s), end(s), '0');
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
