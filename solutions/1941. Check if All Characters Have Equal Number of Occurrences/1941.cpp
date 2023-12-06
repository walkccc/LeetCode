class Solution {
 public:
  bool areOccurrencesEqual(string s) {
    vector<int> count(26);
    for (const char c : s)
      ++count[c - 'a'];
    return equalFreq(count, count[s[0] - 'a']);
  }

 private:
  bool equalFreq(const vector<int>& count, int theFreq) {
    return ranges::all_of(
        count, [theFreq](int freq) { return freq == 0 || freq == theFreq; });
  }
};
