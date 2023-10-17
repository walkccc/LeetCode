class Solution {
  public int minNumberOperations(int[] target) {
    int ans = target[0];

    for (int i = 1; i < target.length; ++i)
      if (target[i] > target[i - 1])
        ans += target[i] - target[i - 1];

    return ans;
  }
}
