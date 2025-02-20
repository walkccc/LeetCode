class Solution {
  public int sumSubarrayMins(int[] arr) {
    final int kMod = 1_000_000_007;
    final int n = arr.length;
    long ans = 0;
    // prevMin[i] := index k s.t. arr[k] is the previous minimum in arr[:i]
    int[] prevMin = new int[n];
    // nextMin[i] := index k s.t. arr[k] is the next minimum in arr[i + 1:]
    int[] nextMin = new int[n];
    Deque<Integer> stack = new ArrayDeque<>();

    Arrays.fill(prevMin, -1);
    Arrays.fill(nextMin, n);

    for (int i = 0; i < arr.length; ++i) {
      while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
        final int index = stack.pop();
        nextMin[index] = i;
      }
      if (!stack.isEmpty())
        prevMin[i] = stack.peek();
      stack.push(i);
    }

    for (int i = 0; i < arr.length; ++i) {
      ans += (long) arr[i] * (i - prevMin[i]) * (nextMin[i] - i);
      ans %= kMod;
    }

    return (int) ans;
  }
}
