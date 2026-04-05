class Solution {
 public:
  vector<int> maxScoreIndices(vector<int>& nums) {
    const int zeros = ranges::count(nums, 0);
    const int ones = nums.size() - zeros;
    vector<int> ans{0};  // the division at index 0
    int leftZeros = 0;
    int leftOnes = 0;
    int maxScore = ones;  // `leftZeros` + `rightOnes`

    for (int i = 0; i < nums.size(); ++i) {
      leftZeros += nums[i] == 0;
      leftOnes += nums[i] == 1;
      const int rightOnes = ones - leftOnes;
      const int score = leftZeros + rightOnes;
      if (maxScore == score) {
        ans.push_back(i + 1);
      } else if (maxScore < score) {
        maxScore = score;
        ans = {i + 1};
      }
    }

    return ans;
  }
};
