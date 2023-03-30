class MaxStack {
 public:
  void push(int x) {
    list.push_front(x);
    keyToIterators[x].push_back(begin(list));
  }

  int pop() {
    const int x = list.front();
    list.pop_front();
    auto& iterators = keyToIterators[x];
    iterators.pop_back();
    if (iterators.empty())
      keyToIterators.erase(x);
    return x;
  }

  int top() {
    return list.front();
  }

  int peekMax() {
    return begin(keyToIterators)->first;
  }

  int popMax() {
    const int x = peekMax();
    auto& iterators = begin(keyToIterators)->second;
    auto it = iterators.back();
    list.erase(it);
    iterators.pop_back();
    if (iterators.empty())
      keyToIterators.erase(begin(keyToIterators));
    return x;
  }

 private:
  std::list<int> list;
  map<int, vector<std::list<int>::iterator>, greater<>> keyToIterators;
};
