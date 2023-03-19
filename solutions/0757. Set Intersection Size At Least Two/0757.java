class Solution {
  public int intersectionSizeTwo(int[][] intervals) {
    int ans = 0;
    int max = -1;
    int secondMax = -1;

    Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);

    for (int[] interval : intervals) {
      final int a = interval[0];
      final int b = interval[1];
      // Max and 2nd max still satisfy
      if (max >= a && secondMax >= a)
        continue;
      if (max >= a) { // Max still satisfy
        secondMax = max;
        max = b; // Add b to the set S
        ans += 1;
      } else {             // Max and 2nd max can't satisfy
        max = b;           // Add b to the set S
        secondMax = b - 1; // Add b - 1 to the set S
        ans += 2;
      }
    }

    return ans;
  }
}
