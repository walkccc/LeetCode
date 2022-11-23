class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    int mask = 1;

    for (int i = 0; i < 30; ++i) {
      const int onesCount = count_if(begin(nums), end(nums),
                                     [&mask](int num) { return num & mask; });
      const int zerosCount = nums.size() - onesCount;
      ans += onesCount * zerosCount;
      mask <<= 1;
    }

    return ans;
  }
};
