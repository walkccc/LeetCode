class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    // l[0] := sum of even-indexed nums[0..i)
    // l[1] := sum of odd-indexed nums[0..i)
    // r[0] := sum of even-indexed nums[i + 1..n)
    // r[1] := sum of odd-indexed nums[i + 1..n)
    vector<int> l(2);
    vector<int> r(2);

    for (int i = 0; i < n; ++i)
      r[i % 2] += nums[i];

    for (int i = 0; i < n; ++i) {
      r[i % 2] -= nums[i];
      if (l[0] + r[1] == l[1] + r[0])
        ++ans;
      l[i % 2] += nums[i];
    }

    return ans;
  }
};
