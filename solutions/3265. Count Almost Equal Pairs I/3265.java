class Solution {
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

  // Returns all possible numbers after 1 swap.
  private Set<Integer> getSwaps(final String digits) {
    final int n = digits.length();
    Set<Integer> swaps = new HashSet<>(Arrays.asList(Integer.parseInt(digits)));

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        char[] newDigits = digits.toCharArray();
        char temp = newDigits[i];
        newDigits[i] = newDigits[j];
        newDigits[j] = temp;
        swaps.add(Integer.parseInt(new String(newDigits)));
      }

    return swaps;
  }
}
