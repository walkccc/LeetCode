class Solution {
  public int[] secondGreaterElement(int[] nums) {
    int[] ans = new int[nums.length];
    Arrays.fill(ans, -1);
    // a decreasing stack that stores indices that met the first greater number
    Deque<Integer> prevStack = new ArrayDeque<>();
    // a decreasing stack that stores indices
    Deque<Integer> currStack = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      // Indices in prevStack meet the second greater num.
      while (!prevStack.isEmpty() && nums[prevStack.peek()] < nums[i])
        ans[prevStack.poll()] = nums[i];
      // Push indices that meet the first greater number from `currStack` to
      // `prevStack`. We need a temporary array to make the indices in the
      // `prevStack` increasing.
      Deque<Integer> decreasingIndices = new ArrayDeque<>();
      while (!currStack.isEmpty() && nums[currStack.peek()] < nums[i])
        decreasingIndices.push(currStack.poll());
      while (!decreasingIndices.isEmpty())
        prevStack.push(decreasingIndices.poll());
      currStack.push(i);
    }

    return ans;
  }
}
