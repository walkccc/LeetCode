class Solution {
  // Similar to 3265. Count Almost Equal Pairs I
  public int countPairs(int[] nums) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();
    final int maxLen = String.valueOf(Arrays.stream(nums).max().getAsInt()).length();

    for (final int num : nums) {
      final String digits = String.format("%0" + maxLen + "d", num);
      for (final int swap : getSwaps(digits))
        ans += count.getOrDefault(swap, 0);
      count.merge(num, 1, Integer::sum);
    }

    return ans;
  }

  // Returns all possible numbers after 1 or 2 swaps.
  private Set<Integer> getSwaps(final String digits) {
    final int n = digits.length();
    Set<Integer> swaps = new HashSet<>(Arrays.asList(Integer.parseInt(digits)));

    // Add all numbers after 1 swap.
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        char[] newDigits = digits.toCharArray();
        char temp = newDigits[i];
        newDigits[i] = newDigits[j];
        newDigits[j] = temp;
        swaps.add(Integer.parseInt(new String(newDigits)));
      }

    // Add all numbers after 2 swaps.
    for (int i1 = 0; i1 < n; ++i1)
      for (int j1 = i1 + 1; j1 < n; ++j1)
        for (int i2 = 0; i2 < n; ++i2)
          for (int j2 = i2 + 1; j2 < n; ++j2) {
            char[] newDigits = digits.toCharArray();
            char temp = newDigits[i1];
            newDigits[i1] = newDigits[j1];
            newDigits[j1] = temp;
            temp = newDigits[i2];
            newDigits[i2] = newDigits[j2];
            newDigits[j2] = temp;
            swaps.add(Integer.parseInt(new String(newDigits)));
          }

    return swaps;
  }
}
