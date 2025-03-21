class Solution {
 public:
  int destroyTargets(vector<int>& nums, int space) {
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num % space];

    return *ranges::max_element(nums, [&count, space](int a, int b) {
      const int countA = count[a % space];
      const int countB = count[b % space];
      return countA == countB ? a > b : countA < countB;
    });
  }
};
