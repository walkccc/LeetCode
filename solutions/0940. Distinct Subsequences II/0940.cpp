class Solution {
 public:
  int distinctSubseqII(string S) {
    constexpr int kMod = 1e9 + 7;

    // endsWith[i] := # of subseqs ends with 'a' + i
    vector<long> endsWith(26);

    for (const char c : S)
      endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % kMod;

    return accumulate(begin(endsWith), end(endsWith), 0L) % kMod;
  }
};
