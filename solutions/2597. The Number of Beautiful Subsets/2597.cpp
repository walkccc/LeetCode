// e.g. nums = [2, 3, 4, 4], k = 2
//
// subset[0] = [2, 4, 4']
// subset[1] = [1]
// count = {2: 1, 4: 2, 1: 1}
//
// Initially, skip = len([]) = 0, pick = len([]) = 0
//
// * For values in subset[0]:
//   After 2:
//     skip = skip + pick = len([]) = 0
//     pick = (2^count[2] - 1) * (1 + skip + pick)
//          = len([[2]]) * len([[]])
//          = len([[2]]) = 1
//   After 4:
//     skip = skip + pick = len([[2]]) = 1
//     pick = (2^count[4] - 1) * (1 + skip)
//          = len([[4], [4'], [4, 4']]) * len([[]])
//          = len([[4], [4'], [4, 4']]) = 3
//
// * For values in subset[1]:
//   After 1:
//     skip = skip + pick
//          = len([[2], [4], [4'], [4, 4']]) = 4
//     pick = (2^count[1] - 1) * (1 + skip + pick)
//          = len([[1]]) * len([[], [2], [4], [4'], [4, 4']])
//          = len([[1], [1, 2], [1, 4], [1, 4'], [1, 4, 4']]) = 5
//
// So, ans = skip + pick = 9

class Solution {
 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    constexpr int kMaxNum = 1000;
    vector<int> count(kMaxNum + 1);
    unordered_map<int, set<int>> modToSubset;

    for (const int num : nums) {
      ++count[num];
      modToSubset[num % k].insert(num);
    }

    int prevNum = -k;
    int skip = 0;
    int pick = 0;

    for (const auto& [_, subset] : modToSubset)
      for (const int num : subset) {
        const int nonEmptyCount = pow(2, count[num]) - 1;
        const int cacheSkip = skip;
        skip += pick;
        pick =
            nonEmptyCount * (1 + cacheSkip + (num - prevNum == k ? 0 : pick));
        prevNum = num;
      }

    return skip + pick;
  }
};
