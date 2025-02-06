class Solution {
  public Solution(int n, int[] blacklist) {
    validRange = n - blacklist.length;

    for (final int b : blacklist)
      map.put(b, -1);

    int maxAvailable = n - 1;

    for (final int b : blacklist)
      if (b < validRange) {
        // Find the slot that haven't been used.
        while (map.containsKey(maxAvailable))
          --maxAvailable;
        map.put(b, maxAvailable--);
      }
  }

  public int pick() {
    final int num = rand.nextInt(validRange);
    return map.getOrDefault(num, num);
  }

  private int validRange;
  private Map<Integer, Integer> map = new HashMap<>();
  private Random rand = new Random();
}
