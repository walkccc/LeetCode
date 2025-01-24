class Solution {
  public int visibleMountains(int[][] peaks) {
    List<Pair<Integer, Integer>> A = deDuplicates(peaks);
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i < A.size(); ++i) {
      while (!stack.isEmpty() && isHidden(A.get(stack.peek()), A.get(i)))
        stack.pop();
      if (!stack.isEmpty() && isHidden(A.get(i), A.get(stack.peek())))
        continue;
      stack.push(i);
    }

    return stack.size();
  }

  private List<Pair<Integer, Integer>> deDuplicates(int[][] peaks) {
    List<Pair<Integer, Integer>> A = new ArrayList<>();
    Map<Pair<Integer, Integer>, Integer> count = new HashMap<>();

    for (int[] peak : peaks)
      count.merge(new Pair<>(peak[0], peak[1]), 1, Integer::sum);

    for (Map.Entry<Pair<Integer, Integer>, Integer> entry : count.entrySet())
      if (entry.getValue() == 1)
        A.add(entry.getKey());

    Collections.sort(A, Comparator.comparing(Pair::getKey));
    return A;
  }

  boolean isHidden(Pair<Integer, Integer> peak1, Pair<Integer, Integer> peak2) {
    final int x1 = peak1.getKey();
    final int y1 = peak1.getValue();
    final int x2 = peak2.getKey();
    final int y2 = peak2.getValue();
    return x1 - y1 >= x2 - y2 && x1 + y1 <= x2 + y2;
  }
}
