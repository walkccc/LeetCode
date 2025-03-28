class Solution {
  public String findSmallestRegion(List<List<String>> regions, String region1, String region2) {
    Map<String, String> parent = new HashMap<>();
    Set<String> ancestors = new HashSet<>(); // region1's ancestors

    for (List<String> region : regions)
      for (int i = 1; i < region.size(); ++i)
        parent.put(region.get(i), region.get(0));

    // Add all the region1's ancestors.
    while (region1 != null) {
      ancestors.add(region1);
      region1 = parent.get(region1); // Region1 becomes null in the end.
    }

    // Go up from region2 until meet any of region1's ancestors.
    while (!ancestors.contains(region2))
      region2 = parent.get(region2);

    return region2;
  }
}
