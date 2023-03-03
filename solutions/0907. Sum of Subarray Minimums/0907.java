class Solution {
  public int sumSubarrayMins(int[] arr) {
    final int kMod = 1_000_000_007;
    final int n = arr.length;
    long ans = 0;
    // prev[i] := index k s.t. arr[k] is the prev min in arr[:i]
    int[] prev = new int[n];
    // next[i] := index k s.t. arr[k] is the next min in arr[i + 1:]
    int[] next = new int[n];
    Deque<Integer> stack = new ArrayDeque<>();

    Arrays.fill(prev, -1);
    Arrays.fill(next, n);

    for (int i = 0; i < arr.length; ++i) {
      while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
        final int index = stack.pop();
        next[index] = i;
      }
      if (!stack.isEmpty())
        prev[i] = stack.peek();
      stack.push(i);
    }

    for (int i = 0; i < arr.length; ++i) {
      ans += (long) arr[i] * (i - prev[i]) * (next[i] - i);
      ans %= kMod;
    }

    return (int) ans;
  }
}
