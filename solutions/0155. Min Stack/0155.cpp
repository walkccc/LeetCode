class MinStack {
 public:
  void push(int x) {
    if (stack.empty())
      stack.push({x, x});
    else
      stack.push({x, min(x, stack.top().second)});
  }

  void pop() {
    stack.pop();
  }

  int top() {
    return stack.top().first;
  }

  int getMin() {
    return stack.top().second;
  }

 private:
  stack<pair<int, int>> stack;  // {x, min}
};
