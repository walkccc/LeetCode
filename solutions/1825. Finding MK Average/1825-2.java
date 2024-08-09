class MyMap {
  public TreeMap<Integer, Integer> map = new TreeMap<>();
  public int size = 0;
  public long sum = 0;
}

class MKAverage {
  public MKAverage(int m, int k) {
    this.m = m;
    this.k = k;
    this.kMidSize = m - 2 * k;
  }

  public void addElement(int num) {
    q.offer(num);
    add(num);

    if (q.size() > m)
      remove(q.poll());
  }

  public int calculateMKAverage() {
    return q.size() == m ? (int) (mid.sum / kMidSize) : -1;
  }

  private final int m;
  private final int k;
  private final int kMidSize;
  private Queue<Integer> q = new ArrayDeque<>();
  private MyMap bot = new MyMap();
  private MyMap mid = new MyMap();
  private MyMap top = new MyMap();

  private void add(int num) {
    add(bot, num);
    if (bot.size > k)
      add(mid, remove(bot, bot.map.lastKey()));
    if (mid.size > kMidSize)
      add(top, remove(mid, mid.map.lastKey()));
  }

  private void remove(int num) {
    if (bot.map.containsKey(num))
      remove(bot, num);
    else if (mid.map.containsKey(num))
      remove(mid, num);
    else
      remove(top, num);

    if (bot.size < k)
      add(bot, remove(mid, mid.map.firstKey()));
    if (mid.size < kMidSize)
      add(mid, remove(top, top.map.firstKey()));
  }

  private void add(MyMap m, int num) {
    m.map.merge(num, 1, Integer::sum);
    ++m.size;
    m.sum += num;
  }

  private int remove(MyMap m, int num) {
    m.map.merge(num, -1, Integer::sum);
    if (m.map.get(num) == 0)
      m.map.remove(num);
    --m.size;
    m.sum -= num;
    return num;
  }
}
