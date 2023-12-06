class Solution {
  public int[][] highFive(int[][] items) {
    List<int[]> ans = new ArrayList<>();
    Map<Integer, PriorityQueue<Integer>> idToScores = new TreeMap<>();

    for (int[] item : items) {
      final int id = item[0];
      final int score = item[1];
      idToScores.putIfAbsent(id, new PriorityQueue<>());
      PriorityQueue<Integer> scores = idToScores.get(id);
      scores.add(score);
      if (scores.size() > 5)
        scores.poll();
    }

    for (Map.Entry<Integer, PriorityQueue<Integer>> entry : idToScores.entrySet()) {
      final int id = entry.getKey();
      PriorityQueue<Integer> scores = entry.getValue();
      int sum = 0;
      while (!scores.isEmpty())
        sum += scores.poll();
      ans.add(new int[] {id, sum / 5});
    }

    return ans.toArray(int[][] ::new);
  }
}
