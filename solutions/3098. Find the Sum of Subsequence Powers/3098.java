class Solution {
  public int sumOfPowers(int[] nums, int k) {
    final int n = nums.length;
    Arrays.sort(nums);
    Integer[][][][] mem = new Integer[n + 1][n + 1][n + 1][k + 1];
    return sumOfPowers(nums, 0, k, -1, -1, -1, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the sum of powers of all subsequences of nums[i..n) which
  // have length equal to k, where `lastPickedIndex` is the index of the last
  // picked number and nums[secondIndex] - nums[firstIndex] is the minimum power
  // so far.
  private int sumOfPowers(int[] nums, int i, int k, int lastPickedIndex, int firstIndex,
                          int secondIndex, Integer[][][][] mem) {
    if (k == 0)
      return nums[secondIndex] - nums[firstIndex];
    if (i == nums.length)
      return 0;
    final int a = hash(lastPickedIndex);
    final int b = hash(firstIndex);
    final int c = hash(secondIndex);
    if (mem[a][b][c][k] != null)
      return mem[a][b][c][k];
    int newFirstIndex = firstIndex;
    int newSecondIndex = secondIndex;
    if (firstIndex == -1) {
      newFirstIndex = i;
    } else if (secondIndex == -1) {
      newSecondIndex = i;
    } else if (nums[i] - nums[lastPickedIndex] < nums[secondIndex] - nums[firstIndex]) {
      newFirstIndex = lastPickedIndex;
      newSecondIndex = i;
    }
    final int pick = sumOfPowers(nums, i + 1, k - 1, i, newFirstIndex, newSecondIndex, mem);
    final int skip = sumOfPowers(nums, i + 1, k, lastPickedIndex, firstIndex, secondIndex, mem);
    return mem[a][b][c][k] = (pick + skip) % kMod;
  }

  private int hash(int x) {
    return x + 1;
  }
}
