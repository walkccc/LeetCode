class Solution {
 public:
  int minDeletions(string s) {
    int ans = 0;
    vector<int> count(26);
    unordered_set<int> usedFreq;

    for (const char c : s)
      ++count[c - 'a'];

    for (int freq : count)
      while (freq > 0 && !usedFreq.insert(freq).second) {
        --freq;  // Delete ('a' + i).
        ++ans;
      }

    return ans;
  }
};
