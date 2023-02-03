class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(128);

    for (const char c : magazine)
      ++count[c];

    for (const char c : ransomNote)
      if (--count[c] < 0)
        return false;

    return true;
  }
};
