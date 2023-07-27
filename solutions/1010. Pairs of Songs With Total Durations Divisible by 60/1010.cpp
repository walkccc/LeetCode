class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int ans = 0;
    vector<int> count(60);

    for (int t : time) {
      t %= 60;
      ans += count[(60 - t) % 60];
      ++count[t];
    }

    return ans;
  }
};
