class MKAverage {
 public:
  MKAverage(int m, int k) : m(m), k(k) {}

  void addElement(int num) {
    q.push(num);
    add(mid, num);
    midSum += num;

    if (q.size() > m) {
      const int removed = q.front();
      q.pop();
      if (top.contains(removed)) {
        remove(top, removed);
        --topSize;
      } else if (mid.contains(removed)) {
        remove(mid, removed);
        midSum -= removed;
      } else {
        remove(bot, removed);
        --botSize;
      }
    }

    // Move item(s) from `mid` to `top` to fill k slots.
    while (!mid.empty() && topSize < k) {
      midSum -= mid.rbegin()->first;
      add(top, remove(mid, mid.rbegin()->first));
      ++topSize;
    }

    // Rebalance `mid` and `top`.
    while (!mid.empty() && mid.rbegin()->first > top.begin()->first) {
      midSum -= mid.rbegin()->first;
      midSum += top.begin()->first;
      add(top, remove(mid, mid.rbegin()->first));
      add(mid, remove(top, top.begin()->first));
    }

    // Move item(s) from `mid` to `bot` to fill k slots.
    while (!mid.empty() && botSize < k) {
      midSum -= mid.begin()->first;
      add(bot, remove(mid, mid.begin()->first));
      ++botSize;
    }

    // Move item(s) from `mid` to `bot` to fill k slots.
    while (!mid.empty() && mid.begin()->first < bot.rbegin()->first) {
      midSum -= mid.begin()->first;
      midSum += bot.rbegin()->first;
      add(bot, remove(mid, mid.begin()->first));
      add(mid, remove(bot, bot.rbegin()->first));
    }
  }

  int calculateMKAverage() {
    return q.size() == m ? midSum / (m - 2 * k) : -1;
  }

 private:
  const int m;
  const int k;
  queue<int> q;
  map<int, int> top;
  map<int, int> mid;
  map<int, int> bot;
  int topSize = 0;
  int botSize = 0;
  long midSum = 0;

  void add(map<int, int>& map, int num) {
    ++map[num];
  }

  int remove(map<int, int>& map, int num) {
    if (--map[num] == 0)
      map.erase(num);
    return num;
  }
};
