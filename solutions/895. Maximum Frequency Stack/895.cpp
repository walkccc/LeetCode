class FreqStack {
 public:
  void push(int val) {
    countToStack[++count[val]].push(val);
    maxFreq = max(maxFreq, count[val]);
  }

  int pop() {
    const int val = countToStack[maxFreq].top();
    countToStack[maxFreq].pop();
    --count[val];
    if (countToStack[maxFreq].empty())
      --maxFreq;
    return val;
  }

 private:
  int maxFreq = 0;
  unordered_map<int, int> count;
  unordered_map<int, stack<int>> countToStack;
};
