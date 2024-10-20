class Solution {
 public:
  vector<int> divisibilityArray(string word, int m) {
    vector<int> ans;
    long prevRemainder = 0;

    for (const char c : word) {
      const long remainder = (prevRemainder * 10 + (c - '0')) % m;
      ans.push_back(remainder == 0 ? 1 : 0);
      prevRemainder = remainder;
    }

    return ans;
  }
};
