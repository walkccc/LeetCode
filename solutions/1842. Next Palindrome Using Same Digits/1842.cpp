class Solution {
 public:
  string nextPalindrome(string num) {
    const int n = num.length();
    vector<int> A(n / 2);

    for (int i = 0; i < A.size(); ++i)
      A[i] = num[i] - '0';

    if (!nextPermutation(A))
      return "";

    string s;

    for (const int a : A)
      s += '0' + a;

    if (n & 1)
      return s + num[n / 2] + string(rbegin(s), rend(s));
    return s + string(rbegin(s), rend(s));
  }

 private:
  // return true if nums has next permutation
  bool nextPermutation(vector<int>& nums) {
    const int n = nums.size();

    // from back to front, find the first num < nums[i + 1]
    int i;
    for (i = n - 2; i >= 0; --i)
      if (nums[i] < nums[i + 1])
        break;

    if (i < 0)
      return false;

    // from back to front, find the first num > nums[i], swap it with nums[i]
    for (int j = n - 1; j > i; --j)
      if (nums[j] > nums[i]) {
        swap(nums[i], nums[j]);
        break;
      }

    // reverse nums[i + 1..n - 1]
    reverse(nums, i + 1, n - 1);
    return true;
  }

  void reverse(vector<int>& nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]);
  }
};
