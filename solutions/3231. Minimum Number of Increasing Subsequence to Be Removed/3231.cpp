class Solution {
 public:
  int minOperations(vector<int>& nums) {
    // The length of the longest non-increasing subsequence is equal to the
    // number of strictly increasing subsequences needed to cover the entire
    // array. This is because any number in the non-increasing subsequence must
    // use one number from each of the strictly increasing subsequences. e.g.,
    // [4, 3, 1, 2] has 3 strictly increasing subsequences: [4], [3], and [1,
    // 2]. The longest non-increasing subsequences are [4, 3, 1] or [4, 3, 2].
    return lengthOfLIS({nums.rbegin(), nums.rend()});
  }

 private:
  // Similar to 300. Longest Increasing Subsequence
  int lengthOfLIS(const vector<int>& nums) {
    // tails[i] := the minimum tail of all the non-decreasing subsequences
    // having length i + 1
    vector<int> tails;

    for (const int num : nums)
      if (tails.empty() || num >= tails.back())
        tails.push_back(num);
      else
        tails[firstGreater(tails, num)] = num;

    return tails.size();
  }

 private:
  int firstGreater(const vector<int>& A, int target) {
    return ranges::upper_bound(A, target) - A.begin();
  }
};
