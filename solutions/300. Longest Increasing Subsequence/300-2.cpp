class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    // It's easy to see that `tails` must be an increasing array.
    vector<int> tails;

    for (const int num : nums)
      if (tails.empty() || num > tails.back())
        tails.push_back(num);
      else
        tails[firstGreaterEqual(tails, num)] = num;

    return tails.size();
  }

 private:
  int firstGreaterEqual(const vector<int>& A, int target) {
    return ranges::lower_bound(A, target) - A.begin();
  }
};
