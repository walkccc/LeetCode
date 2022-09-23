class Solution {
  public int totalStrength(int[] strength) {
    final int kMod = 1_000_000_007;
    final int n = strength.length;
    long[] prefix = new long[n];
    long[] prefixOfPrefix = new long[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i] = i == 0 ? strength[0] : (strength[i] + prefix[i - 1]) % kMod;

    for (int i = 0; i < n; ++i)
      prefixOfPrefix[i + 1] = (prefixOfPrefix[i] + prefix[i]) % kMod;

    // next small or equal on the left
    int[] left = new int[n];
    Arrays.fill(left, -1);
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = n - 1; i >= 0; --i) {
      while (!stack.isEmpty() && strength[stack.peek()] >= strength[i])
        left[stack.pop()] = i;
      stack.push(i);
    }

    // next small on the right
    int[] right = new int[n];
    Arrays.fill(right, n);
    stack = new ArrayDeque<>();

    for (int i = 0; i < n; ++i) {
      while (!stack.isEmpty() && strength[stack.peek()] > strength[i])
        right[stack.pop()] = i;
      stack.push(i);
    }

    long ans = 0;

    // for each strength[i] as minimum, calculate sum
    for (int i = 0; i < n; ++i) {
      final int l = left[i];
      final int r = right[i];
      final long leftSum = prefixOfPrefix[i] - prefixOfPrefix[Math.max(0, l)];
      final long rightSum = prefixOfPrefix[r] - prefixOfPrefix[i];
      final int leftLen = i - l;
      final int rightLen = r - i;
      ans += strength[i] * (rightSum * leftLen % kMod - leftSum * rightLen % kMod + kMod) % kMod;
      ans %= kMod;
    }

    return (int) ans;
  }
}
