class LUPrefix {
  public LUPrefix(int n) {}

  public void upload(int video) {
    seen.add(video);
    while (seen.contains(longestPrefix + 1))
      ++longestPrefix;
  }

  public int longest() {
    return longestPrefix;
  }

  private Set<Integer> seen = new HashSet<>();
  private int longestPrefix = 0;
}
