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
  public int beautifulSubsets(int[] nums, int k) {
    final int MAX = 1000;
    int[] count = new int[MAX + 1];
    Map<Integer, Set<Integer>> modToSubset = new HashMap<>();

    for (final int num : nums) {
      ++count[num];
      modToSubset.putIfAbsent(num % k, new TreeSet<>());
      modToSubset.get(num % k).add(num);
    }

    int prevNum = -k;
    int skip = 0;
    int pick = 0;

    for (Set<Integer> subset : modToSubset.values())
      for (final int num : subset) {
        final int nonEmptyCount = (int) Math.pow(2, count[num]) - 1;
        final int cacheSkip = skip;
        skip += pick;
        pick = nonEmptyCount * (1 + cacheSkip + (num - prevNum == k ? 0 : pick));
        prevNum = num;
      }

    return skip + pick;
  }
}
