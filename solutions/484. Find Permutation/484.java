class Solution {
  public int[] findPermutation(String s) {
    int[] ans = new int[s.length() + 1];
    int ansIndex = 0;
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i < s.length(); ++i) {
      stack.push(i + 1);
      if (s.charAt(i) == 'I')
        while (!stack.isEmpty())
          ans[ansIndex++] = stack.pop();
    }
    stack.push(s.length() + 1);

    while (!stack.isEmpty())
      ans[ansIndex++] = stack.pop();

    return ans;
  }
}
