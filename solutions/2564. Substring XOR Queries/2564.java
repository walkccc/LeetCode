class Solution {
  public int[][] substringXorQueries(String s, int[][] queries) {
    final int kMaxBit = 30;
    int[][] ans = new int[queries.length][2];
    // {val: (left, right)} := s[left..right]'s decimal value = val
    Map<Integer, Pair<Integer, Integer>> valToLeftAndRight = new HashMap<>();

    for (int left = 0; left < s.length(); ++left) {
      int val = 0;
      if (s.charAt(left) == '0') {
        // edge case: Save the index of the first 0.
        if (!valToLeftAndRight.containsKey(0))
          valToLeftAndRight.put(val, new Pair<>(left, left));
        continue;
      }
      final int maxRight = Math.min(s.length(), left + kMaxBit);
      for (int right = left; right < maxRight; ++right) {
        val = val * 2 + s.charAt(right) - '0';
        if (!valToLeftAndRight.containsKey(val))
          valToLeftAndRight.put(val, new Pair<>(left, right));
      }
    }

    for (int i = 0; i < queries.length; ++i) {
      final int first = queries[i][0];
      final int second = queries[i][1];
      final int val = first ^ second;
      Pair<Integer, Integer> leftAndRight = valToLeftAndRight.get(val);
      if (leftAndRight == null) {
        ans[i] = new int[] {-1, -1};
      } else {
        final int left = leftAndRight.getKey();
        final int right = leftAndRight.getValue();
        ans[i] = new int[] {left, right};
      }
    }

    return ans;
  }
}
