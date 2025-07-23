class Solution {
 public:
  bool checkIfCanBreak(string s1, string s2) {
    vector<int> count1(26);
    vector<int> count2(26);

    for (const char c : s1)
      ++count1[c - 'a'];

    for (const char c : s2)
      ++count2[c - 'a'];

    return canBreak(count1, count2) || canBreak(count2, count1);
  }

 private:
  // Returns true if count1 can break count2.
  bool canBreak(const vector<int>& count1, const vector<int>& count2) {
    int diff = 0;
    for (int i = 0; i < 26; ++i) {
      diff += count2[i] - count1[i];
      // count2 is alphabetically greater than count1.
      if (diff < 0)
        return false;
    }
    return true;
  }
};
