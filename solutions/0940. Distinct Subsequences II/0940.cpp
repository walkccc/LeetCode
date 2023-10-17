class Solution {
 public:
  int distinctSubseqII(string s) {
    constexpr int kMod = 1'000'000'007;
    // endsWith[i] := # of subseqs ends with 'a' + i
    vector<long> endsWith(26);

    for (const char c : s)
      endsWith[c - 'a'] =
          accumulate(endsWith.begin(), endsWith.end(), 1L) % kMod;

    return accumulate(endsWith.begin(), endsWith.end(), 0L) % kMod;
  }
};
