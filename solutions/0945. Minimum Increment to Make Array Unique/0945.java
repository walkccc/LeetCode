class Solution {
  public int minIncrementForUnique(int[] A) {
    int ans = 0;
    int minAvailable = 0;

    Arrays.sort(A);

    for (int a : A) {
      ans += Math.max(minAvailable - a, 0);
      minAvailable = Math.max(minAvailable, a) + 1;
    }

    return ans;
  }
}
