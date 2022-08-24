class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    int maxLength = 0;
    vector<int> length(n, 1);  // length[i] := LIS's length ending w/ nums[i]
    vector<int> count(n, 1);   // count[i] := # of the LIS ending w/ nums[i]

    // calculate length and count arrays
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          if (length[i] < length[j] + 1) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          } else if (length[i] == length[j] + 1) {
            count[i] += count[j];
          }

    // get # of LIS
    for (int i = 0; i < n; ++i)
      if (length[i] > maxLength) {
        maxLength = length[i];
        ans = count[i];
      } else if (length[i] == maxLength) {
        ans += count[i];
      }

    return ans;
  }
};
