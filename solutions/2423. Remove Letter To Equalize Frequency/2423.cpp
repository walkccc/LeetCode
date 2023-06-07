class Solution {
 public:
  bool equalFrequency(string word) {
    vector<int> count(26);

    for (const char c : word)
      ++count[c - 'a'];

    // Try to remove each letter, then check if the frequency of all letters in
    // word are equal
    for (const char c : word) {
      --count[c - 'a'];
      if (equalCount(count))
        return true;
      ++count[c - 'a'];
    }

    return false;
  }

 private:
  bool equalCount(const vector<int>& count) {
    int freq = -1;
    for (const int c : count) {
      if (c == 0 || c == freq)
        continue;
      if (freq == -1)
        freq = c;
      else
        return false;
    }
    return true;
  }
};
