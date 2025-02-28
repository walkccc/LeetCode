class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    const int n = nums.size();
    const auto it = nums.begin() + n / 2;
    nth_element(nums.begin(), it, nums.end());
    const int median = *it;

// index-rewiring
#define A(i) nums[(1 + 2 * i) % (n | 1)]

    for (int i = 0, j = 0, k = n - 1; i <= k;)
      if (A(i) > median)
        swap(A(i++), A(j++));
      else if (A(i) < median)
        swap(A(i), A(k--));
      else
        ++i;
  }
};
