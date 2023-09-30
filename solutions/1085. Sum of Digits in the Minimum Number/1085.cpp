class Solution {
 public:
  int sumOfDigits(vector<int>& nums) {
    int min = *min_element(nums.begin(), nums.end());
    int sum = 0;

    while (min > 0) {
      sum += min % 10;
      min /= 10;
    }

    return sum & 1 ^ 1;
  }
};
