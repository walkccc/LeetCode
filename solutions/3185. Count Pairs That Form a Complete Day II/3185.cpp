class Solution {
 public:
  // Same as 3184. Count Pairs That Form a Complete Day I
  long long countCompleteDayPairs(vector<int>& hours) {
    long ans = 0;
    vector<int> count(24);

    for (const int hour : hours) {
      ans += count[(24 - hour % 24) % 24];
      ++count[hour % 24];
    }

    return ans;
  }
};
