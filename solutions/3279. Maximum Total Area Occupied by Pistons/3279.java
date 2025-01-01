class Solution {
  public long maxArea(int height, int[] positions, String directions) {
    long area = Arrays.stream(positions).asLongStream().sum();
    long ans = area;
    long diffPerSecond = 0;
    TreeMap<Integer, List<Integer>> timeToIndices = new TreeMap<>();

    for (int i = 0; i < positions.length; ++i) {
      if (directions.charAt(i) == 'U') {
        timeToIndices.computeIfAbsent(height - positions[i], k -> new ArrayList<>()).add(i);
        timeToIndices.computeIfAbsent(height - positions[i] + height, k -> new ArrayList<>())
            .add(i);
        ++diffPerSecond;
      } else {
        timeToIndices.computeIfAbsent(positions[i], k -> new ArrayList<>()).add(i);
        timeToIndices.computeIfAbsent(positions[i] + height, k -> new ArrayList<>()).add(i);
        --diffPerSecond;
      }
    }

    char[] directionsChars = directions.toCharArray();
    int prevTime = 0;

    for (Map.Entry<Integer, List<Integer>> entry : timeToIndices.entrySet()) {
      final int time = entry.getKey();
      List<Integer> indices = entry.getValue();
      area += (time - prevTime) * diffPerSecond;
      ans = Math.max(ans, area);
      prevTime = time;
      for (final int i : indices)
        if (directionsChars[i] == 'U') {
          directionsChars[i] = 'D';
          diffPerSecond -= 2;
        } else {
          directionsChars[i] = 'U';
          diffPerSecond += 2;
        }
    }

    return ans;
  }
}
