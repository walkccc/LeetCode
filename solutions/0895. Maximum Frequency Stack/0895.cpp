class FreqStack {
 public:
  void push(int x) {
    maxFreq = max(maxFreq, ++count[x]);
    countToStack[count[x]].push(x);
  }

  int pop() {
    int value = countToStack[maxFreq].top();
    --count[value];
    countToStack[maxFreq].pop();
    if (countToStack[maxFreq].empty())
      --maxFreq;
    return value;
  }

 private:
  int maxFreq = 0;
  unordered_map<int, int> count;
  unordered_map<int, stack<int>> countToStack;
};
