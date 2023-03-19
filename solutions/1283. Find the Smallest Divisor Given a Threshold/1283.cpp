class Solution {
 public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int l = 1;
    int r = *max_element(begin(nums), end(nums));

    while (l < r) {
      const int m = (l + r) / 2;
      if (sumDivision(nums, m) <= threshold)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int sumDivision(const vector<int>& nums, int m) {
    int sum = 0;
    for (const int num : nums)
      sum += (num - 1) / m + 1;
    return sum;
  }
};
