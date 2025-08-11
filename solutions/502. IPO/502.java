class Solution {
  public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
    record T(int pro, int cap) {}
    Queue<T> minHeap = new PriorityQueue<>(Comparator.comparing(T::cap));
    Queue<T> maxHeap = new PriorityQueue<>(Comparator.comparing(T::pro, Comparator.reverseOrder()));

    for (int i = 0; i < capital.length; ++i)
      minHeap.offer(new T(profits[i], capital[i]));

    while (k-- > 0) {
      while (!minHeap.isEmpty() && minHeap.peek().cap <= w)
        maxHeap.offer(minHeap.poll());
      if (maxHeap.isEmpty())
        break;
      w += maxHeap.poll().pro;
    }

    return w;
  }
}
