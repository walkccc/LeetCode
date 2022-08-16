class Solution {
  public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
    double ans = Double.MAX_VALUE;
    // workers := [(wagePerQuality, quality)] sorted by wagePerQuality
    Pair<Double, Integer>[] workers = new Pair[quality.length];
    Queue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
    int qualitySum = 0;

    for (int i = 0; i < quality.length; ++i)
      workers[i] = new Pair<>((double) wage[i] / quality[i], quality[i]);

    Arrays.sort(workers, new Comparator<Pair<Double, Integer>>() {
      @Override
      public int compare(Pair<Double, Integer> a, Pair<Double, Integer> b) {
        return Double.compare(a.getKey(), b.getKey());
      }
    });

    for (var worker : workers) {
      final double wagePerQuality = worker.getKey();
      final int q = worker.getValue();
      maxHeap.offer(q);
      qualitySum += q;
      if (maxHeap.size() > k)
        qualitySum -= maxHeap.poll();
      if (maxHeap.size() == k)
        ans = Math.min(ans, qualitySum * wagePerQuality);
    }

    return ans;
  }
}
