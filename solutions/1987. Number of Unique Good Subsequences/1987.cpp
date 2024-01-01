class Solution {
 public:
  // Similar to 940. Distinct Subsequences II
  int numberOfUniqueGoodSubsequences(string binary) {
    constexpr int kMod = 1'000'000'007;
    // endsIn[i] := the number of subsequence that end in ('0' + i)
    vector<int> endsIn(2);

    for (const char c : binary) {
      endsIn[c - '0'] = (endsIn[0] + endsIn[1]) % kMod;
      // Don't count '0' since we want to avoid the leading zeros case.
      // However, we can always count '1'.
      if (c == '1')
        ++endsIn[1];
    }

    // Count '0' in the end.
    return (endsIn[0] + endsIn[1] +
            (binary.find('0') == string::npos ? 0 : 1)) %
           kMod;
  }
};
