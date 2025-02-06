class Solution {
 public:
  int distinctSubseqII(string s) {
    constexpr int kMod = 1'000'000'007;
    // endsIn[i] := the number of subsequence that end in ('a' + i)
    vector<long> endsIn(26);

    for (const char c : s)
      endsIn[c - 'a'] = accumulate(endsIn.begin(), endsIn.end(), 1L) % kMod;

    return accumulate(endsIn.begin(), endsIn.end(), 0L) % kMod;
  }
};
