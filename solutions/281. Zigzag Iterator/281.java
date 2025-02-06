public class ZigzagIterator {
  public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
    if (!v1.isEmpty())
      q.offer(v1.iterator());
    if (!v2.isEmpty())
      q.offer(v2.iterator());
  }

  public int next() {
    final Iterator it = q.poll();
    final int next = (int) it.next();
    if (it.hasNext())
      q.offer(it);
    return next;
  }

  public boolean hasNext() {
    return !q.isEmpty();
  }

  private Queue<Iterator> q = new ArrayDeque<>();
}
