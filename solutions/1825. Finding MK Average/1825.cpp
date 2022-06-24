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
      if (top.count(removed)) {
        remove(top, removed);
        --topSize;
      } else if (mid.count(removed)) {
        remove(mid, removed);
        midSum -= removed;
      } else {
        remove(bot, removed);
        --botSize;
      }
    }

    // move item(s) from mid to top to fill k slots
    while (!mid.empty() && topSize < k) {
      midSum -= rbegin(mid)->first;
      add(top, remove(mid, rbegin(mid)->first));
      ++topSize;
    }

    // rebalance mid and top
    while (!mid.empty() && rbegin(mid)->first > begin(top)->first) {
      midSum -= rbegin(mid)->first;
      midSum += begin(top)->first;
      add(top, remove(mid, rbegin(mid)->first));
      add(mid, remove(top, begin(top)->first));
    }

    // move item(s) from mid to bot to fill k slots
    while (!mid.empty() && botSize < k) {
      midSum -= begin(mid)->first;
      add(bot, remove(mid, begin(mid)->first));
      ++botSize;
    }

    // move item(s) from mid to bot to fill k slots
    while (!mid.empty() && begin(mid)->first < rbegin(bot)->first) {
      midSum -= begin(mid)->first;
      midSum += rbegin(bot)->first;
      add(bot, remove(mid, begin(mid)->first));
      add(mid, remove(bot, rbegin(bot)->first));
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
