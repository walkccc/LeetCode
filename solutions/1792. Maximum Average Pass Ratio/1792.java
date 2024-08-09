class Solution {
  public double maxAverageRatio(int[][] classes, int extraStudents) {
    // (extra pass ratio, pass, total)
    PriorityQueue<T> maxHeap =
        new PriorityQueue<>((a, b) -> Double.compare(b.extraPassRatio, a.extraPassRatio));

    for (int[] c : classes) {
      final int pass = c[0];
      final int total = c[1];
      maxHeap.offer(new T(getExtraPassRatio(pass, total), pass, total));
    }

    for (int i = 0; i < extraStudents; ++i) {
      final int pass = maxHeap.peek().pass;
      final int total = maxHeap.poll().total;
      maxHeap.offer(new T(getExtraPassRatio(pass + 1, total + 1), pass + 1, total + 1));
    }

    double ratioSum = 0;

    while (!maxHeap.isEmpty())
      ratioSum += maxHeap.peek().pass / (double) maxHeap.poll().total;

    return ratioSum / classes.length;
  }

  // Returns the extra pass ratio if a brilliant student joins.
  private double getExtraPassRatio(int pass, int total) {
    return (pass + 1) / (double) (total + 1) - pass / (double) total;
  }

  private record T(double extraPassRatio, int pass, int total){};
}
