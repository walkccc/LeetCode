class Solution {
  public int[] nextGreaterElements(int[] nums) {
    int[] ans = new int[nums.length];
    Arrays.fill(ans, -1);
    Stack<Integer> stack = new Stack<>();

    for (int i = 0; i < nums.length * 2; ++i) {
      int num = nums[i % nums.length];
      while (!stack.isEmpty() && nums[stack.peek()] < num)
        ans[stack.pop()] = num;
      if (i < nums.length)
        stack.push(i);
    }

    return ans;
  }
}