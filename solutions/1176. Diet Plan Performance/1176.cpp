class Solution {
 public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int ans = 0;
    int sum = 0;

    for (int i = 0; i < calories.size(); ++i) {
      sum += calories[i];
      if (i < k - 1)
        continue;
      if (i >= k)
        sum -= calories[i - k];
      if (sum < lower)
        --ans;
      else if (sum > upper)
        ++ans;
    }

    return ans;
  }
};
