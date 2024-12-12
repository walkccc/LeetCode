class Solution {
 public:
  int countCompleteDayPairs(vector<int>& hours) {
    int ans = 0;
    vector<int> count(24);

    for (const int hour : hours) {
      ans += count[(24 - hour % 24) % 24];
      ++count[hour % 24];
    }

    return ans;
  }
};
