class Solution {
 public:
  int beautifulNumbers(int l, int r) {
    return count(to_string(r), 0, /*tight=*/true, /*isLeadingZero=*/true,
                 /*hasZero=*/false, /*sum=*/0, /*prod=*/1, {}) -
           count(to_string(l - 1), 0, /*tight=*/true, /*isLeadingZero=*/true,
                 /*hasZero=*/false, /*sum=*/0, /*prod=*/1, {});
  }

 private:
  int count(const string& s, int i, bool tight, bool isLeadingZero,
            bool hasZero, int sum, int prod, unordered_map<string, int>&& mem) {
    if (i == s.length()) {
      if (isLeadingZero)
        return 0;
      return (hasZero || prod % sum == 0) ? 1 : 0;
    }
    const string key = hash(i, tight, isLeadingZero, hasZero, sum, prod);
    if (!isLeadingZero && hasZero && !tight)
      return mem[key] = pow(10, s.length() - i);
    if (const auto it = mem.find(key); it != mem.end())
      return it->second;

    int res = 0;
    const int maxDigit = tight ? s[i] - '0' : 9;

    for (int d = 0; d <= maxDigit; ++d) {
      const bool nextTight = tight && (d == maxDigit);
      const bool nextIsLeadingZero = isLeadingZero && d == 0;
      const bool nextHasZero = !nextIsLeadingZero && d == 0;
      const int nextProd = nextIsLeadingZero ? 1 : prod * d;
      res += count(s, i + 1, nextTight, nextIsLeadingZero, nextHasZero, sum + d,
                   nextProd, std::move(mem));
    }

    return mem[key] = res;
  }

  string hash(int i, bool tight, bool isLeadingZero, bool hasZero, int sum,
              int prod) {
    return to_string(i) + "_" + (tight ? "1" : "0") + "_" +
           (isLeadingZero ? "1" : "0") + "_" + (hasZero ? "1" : "0") + "_" +
           to_string(sum) + "_" + to_string(prod);
  }
};
