class Solution {
  public int earliestFullBloom(int[] plantTime, int[] growTime) {
    record Seed(int p, int g) {}
    final int n = plantTime.length;
    int ans = 0;
    int time = 0;
    Seed[] seeds = new Seed[n];

    for (int i = 0; i < plantTime.length; ++i)
      seeds[i] = new Seed(plantTime[i], growTime[i]);

    Arrays.sort(seeds, (a, b) -> Integer.compare(b.g, a.g));

    for (Seed seed : seeds) {
      time += seed.p;
      ans = Math.max(ans, time + seed.g);
    }

    return ans;
  }
}
