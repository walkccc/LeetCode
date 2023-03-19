class Solution {
 public:
  // Similar to 940. Distinct Subsequences II
  int numberOfUniqueGoodSubsequences(string binary) {
    constexpr int kMod = 1'000'000'007;
    // endsWith[i] := # of subseqs ends with '0' + i
    vector<int> endsWith(2);

    for (const char c : binary) {
      endsWith[c - '0'] = (endsWith[0] + endsWith[1]) % kMod;
      // Don't cound '0' since we want to avoid the leading zeros case.
      // However, we can always count '1'.
      if (c == '1')
        ++endsWith[1];
    }

    // Count '0' in the end.
    return (endsWith[0] + endsWith[1] +
            (binary.find('0') == string::npos ? 0 : 1)) %
           kMod;
  }
};
