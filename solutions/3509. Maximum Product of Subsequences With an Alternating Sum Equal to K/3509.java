enum State {
  FIRST,    // first element - add to sum and start product
  SUBTRACT, // second element - subtract from sum and multiply product
  ADD       // third element - add to sum and multiply product
}

class Solution {
  public int maxProduct(int[] nums, int k, int limit) {
    if (Math.abs(k) > Arrays.stream(nums).sum())
      return -1;
    final Map<String, Integer> mem = new HashMap<>();
    final int ans = maxProduct(nums, 0, 1, State.FIRST, k, limit, mem);
    return ans == MIN ? -1 : ans;
  }

  private static final int MIN = -5000;

  private int maxProduct(int[] nums, int i, int product, State state, int k, int limit,
                         Map<String, Integer> mem) {
    if (i == nums.length)
      return k == 0 && state != State.FIRST && product <= limit ? product : MIN;
    final String key = i + "," + k + "," + product + "," + state.ordinal();
    if (mem.containsKey(key))
      return mem.get(key);
    int res = maxProduct(nums, i + 1, product, state, k, limit, mem);
    if (state == State.FIRST)
      res =
          Math.max(res, maxProduct(nums, i + 1, nums[i], State.SUBTRACT, k - nums[i], limit, mem));
    if (state == State.SUBTRACT)
      res = Math.max(res, maxProduct(nums, i + 1, Math.min(product * nums[i], limit + 1), State.ADD,
                                     k + nums[i], limit, mem));
    if (state == State.ADD)
      res = Math.max(res, maxProduct(nums, i + 1, Math.min(product * nums[i], limit + 1),
                                     State.SUBTRACT, k - nums[i], limit, mem));
    mem.put(key, res);
    return res;
  }
}
