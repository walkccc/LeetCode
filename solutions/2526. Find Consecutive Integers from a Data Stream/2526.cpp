class DataStream {
 public:
  DataStream(int value, int k) : value(value), k(k) {}

  bool consec(int num) {
    if (q.size() == k) {
      if (q.front() == value)
        --count;
      q.pop();
    }
    if (num == value)
      ++count;
    q.push(num);
    return count == k;
  }

 private:
  const int value;
  const int k;
  queue<int> q;
  int count = 0;
};
