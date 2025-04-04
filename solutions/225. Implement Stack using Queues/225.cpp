class MyStack {
 public:
  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    const int val = q.front();
    q.pop();
    return val;
  }

  int top() {
    return q.front();
  }

  bool empty() {
    return q.empty();
  }

 private:
  queue<int> q;
};
