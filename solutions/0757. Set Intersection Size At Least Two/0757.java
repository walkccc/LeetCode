class Solution {
  public int intersectionSizeTwo(int[][] intervals) {
    int ans = 0;
    int max = -1;
    int secondMax = -1;

    Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);

    for (int[] interval : intervals) {
      final int a = interval[0];
      final int b = interval[1];
      // max and 2nd max still satisfy
      if (max >= a && secondMax >= a)
        continue;
      if (max >= a) { // max still satisfy
        secondMax = max;
        max = b; // add b to the set S
        ans += 1;
      } else {             // max and 2nd max can't satisfy
        max = b;           // add b to the set S
        secondMax = b - 1; // add b - 1 to the set S
        ans += 2;
      }
    }

    return ans;
  }
}
