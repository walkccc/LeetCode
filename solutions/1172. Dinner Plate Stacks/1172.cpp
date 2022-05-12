class DinnerPlates {
 public:
  DinnerPlates(int capacity) : capacity(capacity) {
    minHeap.push(0);
  }

  void push(int val) {
    const int index = minHeap.top();
    // add new stack on demand
    if (index == stacks.size())
      stacks.push_back({});
    // push the new value
    stacks[index].push(val);
    // if the stack pushed is full, remove its candidacy from minHeap
    if (stacks[index].size() == capacity) {
      minHeap.pop();
      // if minHeap is empty, the next available stack index is stacks.size()
      if (minHeap.empty())
        minHeap.push(stacks.size());
    }
  }

  int pop() {
    // remove empty stacks from back
    while (!stacks.empty() && stacks.back().empty())
      stacks.pop_back();
    if (stacks.empty())
      return -1;
    return popAtStack(stacks.size() - 1);
  }

  int popAtStack(int index) {
    if (index >= stacks.size() || stacks[index].empty())
      return -1;
    // if the stack is going to have space, add its candiday to minHeap
    if (stacks[index].size() == capacity)
      minHeap.push(index);
    const int val = stacks[index].top();
    stacks[index].pop();
    return val;
  }

 private:
  const int capacity;
  vector<stack<int>> stacks;
  // min stacks to push
  priority_queue<int, vector<int>, greater<>> minHeap;
};
