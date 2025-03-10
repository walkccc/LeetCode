class CustomStack {
 public:
  CustomStack(int maxSize) : maxSize(maxSize) {}

  void push(int x) {
    if (stack.size() == maxSize)
      return;
    stack.push(x);
    pendingIncrements.push_back(0);
  }

  int pop() {
    if (stack.empty())
      return -1;
    const int i = stack.size() - 1;
    if (i > 0)
      pendingIncrements[i - 1] += pendingIncrements[i];
    const int val = stack.top() + pendingIncrements[i];
    stack.pop();
    pendingIncrements.pop_back();
    return val;
  }

  void increment(int k, int val) {
    if (stack.empty())
      return;
    const int i = min(k - 1, static_cast<int>(stack.size()) - 1);
    pendingIncrements[i] += val;
  }

 private:
  const int maxSize;
  stack<int> stack;
  // pendingIncrements[i] := the pending increment for stack[0..i].
  vector<int> pendingIncrements;
};
