class Solution {
 public:
  bool equalFrequency(string word) {
    vector<int> count(26);

    for (const char c : word)
      ++count[c - 'a'];

    // Try to remove each letter, then check if the frequency of all the letters
    // in the `word` are equal.
    for (const char c : word) {
      --count[c - 'a'];
      if (equalFreq(count))
        return true;
      ++count[c - 'a'];
    }

    return false;
  }

 private:
  bool equalFreq(const vector<int>& count) {
    int theFreq = -1;
    for (const int freq : count) {
      if (freq == 0 || freq == theFreq)
        continue;
      if (theFreq == -1)
        theFreq = freq;
      else
        return false;
    }
    return true;
  }
};
