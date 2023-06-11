class Solution {
  public int[] secondGreaterElement(int[] nums) {
    int[] ans = new int[nums.length];
    Arrays.fill(ans, -1);
    // decreasing stack that stores indices that met the first greater num
    Deque<Integer> prevStack = new ArrayDeque<>();
    // decreasing stack that stores indices
    Deque<Integer> currStack = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      // Indices in prevStack meet the second greater num.
      while (!prevStack.isEmpty() && nums[prevStack.peek()] < nums[i])
        ans[prevStack.poll()] = nums[i];
      // Push indices that meet the first greater num from `currStack` to
      // `prevStack`. We need a temp array to make indices in `prevStack`
      // increasing.
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
