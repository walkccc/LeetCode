class Solution {
 public:
  int numberOfBeams(vector<string>& bank) {
    int ans = 0;
    int prevOnes = 0;

    for (const auto& row : bank) {
      const int ones = count(begin(row), end(row), '1');
      if (ones) {
        ans += prevOnes * ones;
        prevOnes = ones;
      }
    }

    return ans;
  }
};
