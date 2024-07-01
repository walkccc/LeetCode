class MovingAverage {
 public:
  MovingAverage(int size) : size(size) {}

  double next(int val) {
    if (q.size() == size)
      sum -= q.front(), q.pop();
    sum += val;
    q.push(val);
    return sum / q.size();
  }

 private:
  int size;
  double sum = 0;
  queue<int> q;
};
