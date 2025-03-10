class Solution {
  public int maxPotholes(String road, int budget) {
    int ans = 0;

    for (final int length : getSortedPotholeLengths(road)) {
      final int canRepair = Math.max(0, budget - 1);
      if (length > canRepair)
        return ans + canRepair;
      ans += length;
      budget -= length + 1;
    }

    return ans;
  }

  private List<Integer> getSortedPotholeLengths(final String road) {
    List<Integer> potholeLengths = new ArrayList<>();
    for (String pothole : road.split("\\."))
      potholeLengths.add(pothole.length());
    Collections.sort(potholeLengths, Collections.reverseOrder());
    return potholeLengths;
  }
}
