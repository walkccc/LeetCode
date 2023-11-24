class Solution {
 public:
  int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    int ans = -1;
    int maxScore = -1;

    for (const int divisor : divisors) {
      const int score = ranges::count_if(
          nums, [divisor](const int num) { return num % divisor == 0; });
      if (score > maxScore) {
        ans = divisor;
        maxScore = score;
      } else if (score == maxScore) {
        ans = min(ans, divisor);
      }
    }

    return ans;
  }
};
