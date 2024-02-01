class Seed {
  public int p;
  public int g;
  public Seed(int p, int g) {
    this.p = p;
    this.g = g;
  }
};

class Solution {
  public int earliestFullBloom(int[] plantTime, int[] growTime) {
    int ans = 0;
    int time = 0;
    Seed[] seeds = new Seed[n];

    for (int i = 0; i < plantTime.length; ++i)
      seeds[i] = new Seed(plantTime[i], growTime[i]);

    Arrays.sort(seeds, (a, b) -> b.g - a.g);

    for (Seed seed : seeds) {
      time += seed.p;
      ans = Math.max(ans, time + seed.g);
    }

    return ans;
  }
}
