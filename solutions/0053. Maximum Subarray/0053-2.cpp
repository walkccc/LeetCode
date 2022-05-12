struct T {
  int left;   // sum of the subarray w/ max sum (starting from the first num)
  int right;  // sum of the subarray w/ max sum (ending at the the last num)
  int mid;    // sum of the subarray w/ max sum
  int sum;    // sum of the whole array
};

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    return divideAndConquer(nums, 0, nums.size() - 1).mid;
  }

 private:
  T divideAndConquer(const vector<int>& nums, int l, int r) {
    if (l == r)
      return {nums[l], nums[l], nums[l], nums[l]};

    const int m = (l + r) / 2;
    const T t1 = divideAndConquer(nums, l, m);
    const T t2 = divideAndConquer(nums, m + 1, r);

    const int left = max(t1.left, t1.sum + t2.left);
    const int right = max(t1.right + t2.sum, t2.right);
    const int mid = max({t1.right + t2.left, t1.mid, t2.mid});
    const int sum = t1.sum + t2.sum;
    return {left, right, mid, sum};
  }
};
