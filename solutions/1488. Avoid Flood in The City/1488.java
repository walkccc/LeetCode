class Solution {
  public int[] avoidFlood(int[] rains) {
    int[] ans = new int[rains.length];
    Arrays.fill(ans, -1);
    Map<Integer, Integer> lakeIdToFullDay = new HashMap<>();
    TreeSet<Integer> emptyDays = new TreeSet<>(); // indices of rains[i] == 0

    for (int i = 0; i < rains.length; ++i) {
      final int lakeId = rains[i];
      if (lakeId == 0) {
        emptyDays.add(i);
        continue;
      }
      if (lakeIdToFullDay.containsKey(lakeId)) {
        final int fullDay = lakeIdToFullDay.get(lakeId);
        // The lake was full in a previous day. Greedily find the closest day
        // to make the lake empty.
        Integer emptyDay = emptyDays.higher(fullDay);
        if (emptyDay == null) // Not found.
          return new int[] {};
        // Empty the lake at this day.
        ans[emptyDay] = lakeId;
        emptyDays.remove(emptyDay);
      }
      // The lake with `lakeId` becomes full at the day `i`.
      lakeIdToFullDay.put(lakeId, i);
    }

    // Empty an arbitrary lake if there are remaining empty days.
    for (final int emptyDay : emptyDays)
      ans[emptyDay] = 1;

    return ans;
  }
}
