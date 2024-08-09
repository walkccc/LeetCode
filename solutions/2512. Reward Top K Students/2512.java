class Solution {
  public List<Integer> topStudents(String[] positive_feedback, String[] negative_feedback,
                                   String[] report, int[] student_id, int k) {
    List<Integer> ans = new ArrayList<>();
    Pair<Integer, Integer>[] scoreAndIds = new Pair[report.length];
    Set<String> pos = Arrays.stream(positive_feedback).collect(Collectors.toSet());
    Set<String> neg = Arrays.stream(negative_feedback).collect(Collectors.toSet());

    for (int i = 0; i < report.length; ++i) {
      int score = 0;
      for (final String word : report[i].split(" ")) {
        if (pos.contains(word))
          score += 3;
        if (neg.contains(word))
          score -= 1;
      }
      scoreAndIds[i] = new Pair<>(score, student_id[i]);
    }

    Arrays.sort(scoreAndIds,
                (a, b)
                    -> a.getKey().equals(b.getKey()) ? a.getValue() - b.getValue()
                                                     : b.getKey() - a.getKey());

    for (int i = 0; i < k; ++i)
      ans.add(scoreAndIds[i].getValue());
    return ans;
  }
}
