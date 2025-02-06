class Solution {
 public:
  int maxDifference(string s) {
    vector<int> count(26);
    int maxOdd = 0;
    int minEven = s.length();

    for (const char c : s)
      ++count[c - 'a'];

    for (const int freq : count) {
      if (freq == 0)
        continue;
      if (freq % 2 == 0)
        minEven = min(minEven, freq);
      else
        maxOdd = max(maxOdd, freq);
    }

    return maxOdd - minEven;
  }
};
