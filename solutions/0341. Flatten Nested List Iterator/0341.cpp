class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    addInteger(nestedList);
  }

  int next() {
    const int num = q.front();
    q.pop();
    return num;
  }

  bool hasNext() {
    return !q.empty();
  }

 private:
  queue<int> q;

  void addInteger(const vector<NestedInteger>& nestedList) {
    for (const NestedInteger& ni : nestedList)
      if (ni.isInteger())
        q.push(ni.getInteger());
      else
        addInteger(ni.getList());
  }
};
