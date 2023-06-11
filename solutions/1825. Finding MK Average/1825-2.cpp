struct MyMap {
  map<int, int> map;
  int size = 0;
  long sum = 0;
};

class MKAverage {
 public:
  MKAverage(int m, int k) : m(m), k(k), kMidSize(m - 2 * k) {}

  void addElement(int num) {
    q.push(num);
    add(num);

    if (q.size() > m) {
      const int removed = q.front();
      q.pop();
      remove(removed);
    }
  }

  int calculateMKAverage() {
    return q.size() == m ? mid.sum / kMidSize : -1;
  }

 private:
  const int m;
  const int k;
  const int kMidSize;
  queue<int> q;
  MyMap top;
  MyMap mid;
  MyMap bot;

  void add(int num) {
    add(bot, num);
    if (bot.size > k)
      add(mid, remove(bot, rbegin(bot.map)->first));
    if (mid.size > kMidSize)
      add(top, remove(mid, rbegin(mid.map)->first));
  }

  void remove(int num) {
    if (bot.map.count(num))
      remove(bot, num);
    else if (mid.map.count(num))
      remove(mid, num);
    else
      remove(top, num);

    if (bot.size < k)
      add(bot, remove(mid, begin(mid.map)->first));
    if (mid.size < kMidSize)
      add(mid, remove(top, begin(top.map)->first));
  }

  void add(MyMap& m, int num) {
    ++m.map[num];
    ++m.size;
    m.sum += num;
  }

  int remove(MyMap& m, int num) {
    if (--m.map[num] == 0)
      m.map.erase(num);
    --m.size;
    m.sum -= num;
    return num;
  }
};
