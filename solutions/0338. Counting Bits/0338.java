class Solution {
  public int[] countBits(int num) {
    // let f(i) := i's # of 1's in binary representation
    // f(i) = f(i / 2) + i % 2
    int[] ans = new int[num + 1];

    for (int i = 1; i <= num; ++i)
      ans[i] = ans[i / 2] + (i % 2 == 0 ? 0 : 1);

    return ans;
  }
}
