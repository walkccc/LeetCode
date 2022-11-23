class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    addInteger(nestedList);
  }

  int next() {
    const int num = stack.top().getInteger();
    stack.pop();
    return num;
  }

  bool hasNext() {
    while (!stack.empty() && !stack.top().isInteger()) {
      vector<NestedInteger> nestedList = stack.top().getList();
      stack.pop();
      addInteger(nestedList);
    }
    return !stack.empty();
  }

 private:
  stack<NestedInteger> stack;

  // AddInteger([1, [4, [6]]]) -> stack = [[4, [6]], 1]
  // AddInteger([4, [6]]) -> stack = [[6], 4]
  // AddInteger([6]) -> stack = [6]
  void addInteger(const vector<NestedInteger>& nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i)
      stack.push(nestedList[i]);
  }
};
