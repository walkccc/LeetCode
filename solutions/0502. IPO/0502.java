class T {
  public int pro;
  public int cap;

  public T(int pro, int cap) {
    this.pro = pro;
    this.cap = cap;
  }
};

class Solution {
  public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
    PriorityQueue<T> pqCap = new PriorityQueue<>((a, b) -> a.cap - b.cap);
    PriorityQueue<T> pqPro = new PriorityQueue<>((a, b) -> b.pro - a.pro);

    for (int i = 0; i < Capital.length; ++i)
      pqCap.offer(new T(Profits[i], Capital[i]));

    while (k-- > 0) {
      while (!pqCap.isEmpty() && pqCap.peek().cap <= W)
        pqPro.offer(pqCap.poll());
      if (pqPro.isEmpty())
        break;
      W += pqPro.poll().pro;
    }

    return W;
  }
}
