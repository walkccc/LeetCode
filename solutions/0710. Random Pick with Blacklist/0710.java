class Solution {
  public Solution(int N, int[] blacklist) {
    validRange = N - blacklist.length;

    for (int b : blacklist)
      map.put(b, -1);

    for (int b : blacklist)
      if (b < validRange) {
        while (map.containsKey(N - 1))
          --N;
        map.put(b, --N);
      }
  }

  public int pick() {
    int value = rand.nextInt(validRange);
    return map.getOrDefault(value, value);
  }

  private int validRange;
  private Map<Integer, Integer> map = new HashMap<>();
  private Random rand = new Random();
}