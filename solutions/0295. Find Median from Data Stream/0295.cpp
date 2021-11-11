class MedianFinder {
 public:
  void addNum(int num) {
    if (l.empty() || num <= l.top())
      l.push(num);
    else
      r.push(num);

    // balance two heaps s.t. |l| >= |r| and |l| - |r| <= 1
    if (l.size() < r.size())
      l.push(r.top()), r.pop();
    else if (l.size() - r.size() > 1)
      r.push(l.top()), l.pop();
  }

  double findMedian() {
    if (l.size() == r.size())
      return (l.top() + r.top()) / 2.0;
    return l.top();
  }

 private:
  priority_queue<int> l;                          // max-heap
  priority_queue<int, vector<int>, greater<>> r;  // min-heap
};
