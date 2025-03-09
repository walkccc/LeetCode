class Solution {
  public int[] countOfPairs(int n, int x, int y) {
    if (x > y) {
      final int temp = x;
      x = y;
      y = temp;
    }

    final int ringLen = y - x + 1;
    final int leftLineLen = x - 1;
    final int rightLineLen = n - y;

    int[] ans = new int[n];
    ans = addVectors(ans, bothInRing(n, ringLen));
    ans = addVectors(ans, bothInTheSameLine(n, leftLineLen));
    ans = addVectors(ans, bothInTheSameLine(n, rightLineLen));
    ans = addVectors(ans, lineToRing(n, leftLineLen, ringLen));
    ans = addVectors(ans, lineToRing(n, rightLineLen, ringLen));
    ans = addVectors(ans, lineToLine(n, x, y, leftLineLen, rightLineLen));
    for (int i = 0; i < ans.length; ++i)
      ans[i] *= 2;
    return ans;
  }

  // Returns the contribution from the scenario where two houses are located in
  // the ring.
  private int[] bothInRing(int n, int ringLen) {
    int[] res = new int[n];
    for (int k = 1; k <= (ringLen - 1) / 2; ++k)
      res[k - 1] += ringLen;
    if (ringLen % 2 == 0)
      res[ringLen / 2 - 1] += ringLen / 2;
    return res;
  }

  // Returns the contribution from the scenario where two houses are either
  // located in the left line [1, x) or the right line (y, n].
  private int[] bothInTheSameLine(int n, int lineLen) {
    int[] res = new int[n];
    for (int k = 1; k <= lineLen; ++k)
      res[k - 1] += lineLen - k;
    return res;
  }

  // Returns the contribution from the scenario where one house is either
  // located in the left line [1, x) or the right line (y, n] and the other
  // house is located in the cycle.
  private int[] lineToRing(int n, int lineLen, int ringLen) {
    int[] res = new int[n];
    for (int k = 1; k <= lineLen + ringLen; ++k) {
      // min(
      //   at most k - 1 since we need to give 1 to the line,
      //   at most ringLen / 2 since for length > ringLen / 2, it can always be
      //     calculated as ringLen - ringLen / 2
      // )
      final int maxInRingLen = Math.min(k - 1, ringLen / 2);
      // max(at least 0, at lest k - lineLen)
      final int minInRingLen = Math.max(0, k - lineLen);
      if (minInRingLen <= maxInRingLen) {
        // Each ring length contributes 2 to the count due to the split of
        // paths when entering the ring: One path traverses the upper half of
        // the ring, and the other traverses the lower half.
        // This is illustrated as follows:
        //   Path 1: ... -- x -- (upper half of the ring)
        //   Path 2: ... -- x -- (lower half of the ring)
        res[k - 1] += (maxInRingLen - minInRingLen + 1) * 2;
        if (minInRingLen == 0)
          // Subtract 1 since there's no split.
          res[k - 1] -= 1;
        if (maxInRingLen * 2 == ringLen)
          // Subtract 1 since the following case only contribute one:
          //   ... -- x -- (upper half of the ring) -- middle point
          //   ... -- x -- (upper half of the ring) -- middle point
          res[k - 1] -= 1;
      }
    }
    return res;
  }

  // Returns the contribution from the scenario where one house is in the left
  // line [1, x) and the other house is in the right line (y, n].
  private int[] lineToLine(int n, int x, int y, int leftLineLen, int rightLineLen) {
    int[] res = new int[n];
    for (int k = 1; k <= leftLineLen + rightLineLen + 2; ++k) {
      // min(
      //   at most leftLineLen,
      //   at most k - 1 - (x < y) since we need to give 1 to the right line
      //     and if x < y we need to give another 1 to "x - y".
      // )
      final int maxInLeft = Math.min(leftLineLen, k - 1 - (x < y ? 1 : 0));
      // max(at least 1, at least k - rightLineLen - (x < y))
      final int minInLeft = Math.max(1, k - rightLineLen - (x < y ? 1 : 0));
      if (minInLeft <= maxInLeft)
        res[k - 1] += maxInLeft - minInLeft + 1;
    }
    return res;
  }

  private int[] addVectors(int[] a, int[] b) {
    for (int i = 0; i < a.length; ++i)
      a[i] += b[i];
    return a;
  }
}
