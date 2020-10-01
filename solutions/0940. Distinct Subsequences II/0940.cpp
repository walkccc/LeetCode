class Solution {
 public:
  int distinctSubseqII(string S) {
    const int kMod = 1e9 + 7;

    vector<long> map(26);

    for (char c : S) map[c - 'a'] = accumulate(begin(map), end(map), 1L) % kMod;

    return accumulate(begin(map), end(map), 0L) % kMod;
  }
};