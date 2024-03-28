class Solution {
  public int[][] averageHeightOfBuildings(int[][] buildings) {
    List<int[]> ans = new ArrayList<>();
    List<Pair<Integer, Integer>> events = new ArrayList<>();

    for (int[] b : buildings) {
      final int start = b[0];
      final int end = b[1];
      final int height = b[2];
      events.add(new Pair<>(start, height));
      events.add(new Pair<>(end, -height));
    }

    Collections.sort(events, Comparator.comparing(Pair::getKey));

    int prev = 0;
    int count = 0;
    int sumHeight = 0;

    for (Pair<Integer, Integer> event : events) {
      final int curr = event.getKey();
      final int h = event.getValue();
      final int height = Math.abs(h);
      if (sumHeight > 0 && curr > prev) {
        final int avgHeight = sumHeight / count;
        if (!ans.isEmpty() && ans.get(ans.size() - 1)[1] == prev &&
            avgHeight == ans.get(ans.size() - 1)[2])
          ans.get(ans.size() - 1)[1] = curr;
        else
          ans.add(new int[] {prev, curr, avgHeight});
      }
      sumHeight += h;
      count += h > 0 ? 1 : -1;
      prev = curr;
    }

    return ans.stream().toArray(int[][] ::new);
  }
}
