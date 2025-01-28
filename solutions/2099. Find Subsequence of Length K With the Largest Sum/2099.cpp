class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> ans;
    vector<int> A(nums);
    nth_element(A.begin(), A.end() - k, A.end());
    const int threshold = A[A.size() - k];
    const int larger =
        ranges::count_if(nums, [&](int num) { return num > threshold; });
    int equal = k - larger;

    for (const int num : nums)
      if (num > threshold) {
        ans.push_back(num);
      } else if (num == threshold && equal) {
        ans.push_back(num);
        --equal;
      }

    return ans;
  }
};
