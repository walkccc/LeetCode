class Solution {
 public:
  int beautifulSplits(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    // z[start][i] := the z array of nums[i..n) with respect to nums[start..n)
    vector<vector<int>> z;

    for (int start = 0; start < n; ++start)
      z.push_back(zFunction(nums, start));

    // nums1 | nums2 | nums3 = nums[0..i] | nums[i + 1..j] | nums[j + 1..n - 1]
    for (int i = 0; i < n - 2; ++i)
      for (int j = i + 1; j < n - 1; ++j)
        if ((j - i >= i + 1 &&
             z[0][i + 1] >= i + 1) ||  // nums1 is a prefix of nums2.
            z[i + 1][j + 1] >= j - i)  // nums2 is a suffix of nums3.
          ++ans;

    return ans;
  }

 private:
  // Returns the z array, where z[i] is the length of the longest prefix of
  // nums[i..n) which is also a prefix of nums[start..n).
  vector<int> zFunction(const vector<int>& nums, int start) {
    const int n = nums.size();
    vector<int> z(n);
    int l = 0;
    int r = 0;
    for (int i = 1 + start; i < n; ++i) {
      if (i < r)
        z[i] = min(r - i, z[i - l + start]);
      while (i + z[i] < n && nums[z[i] + start] == nums[i + z[i]])
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }
};
