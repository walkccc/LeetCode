class Solution {
  public int numberOfPoints(List<List<Integer>> nums) {
    final int MAX = 100;
    int ans = 0;
    int runningSum = 0;
    int[] count = new int[MAX + 2];

    for (List<Integer> num : nums) {
      final int start = num.get(0);
      final int end = num.get(1);
      ++count[start];
      --count[end + 1];
    }

    for (int i = 1; i <= MAX; i++) {
      runningSum += count[i];
      if (runningSum > 0)
        ++ans;
    }

    return ans;
  }
}
