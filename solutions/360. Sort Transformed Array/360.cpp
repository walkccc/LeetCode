class Solution {
 public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    const int n = nums.size();
    const bool upward = a > 0;
    vector<int> ans(n);
    vector<int> quad;

    for (const int num : nums)
      quad.push_back(f(num, a, b, c));

    int i = upward ? n - 1 : 0;
    for (int l = 0, r = n - 1; l <= r;)
      if (upward)  // is the maximum in the both ends
        ans[i--] = quad[l] > quad[r] ? quad[l++] : quad[r--];
      else  // is the minimum in the both ends
        ans[i++] = quad[l] < quad[r] ? quad[l++] : quad[r--];

    return ans;
  }

 private:
  // The concavity of f only depends on a's sign.
  int f(int x, int a, int b, int c) {
    return (a * x + b) * x + c;
  }
};
