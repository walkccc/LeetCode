class FreqStack {
  public void push(int val) {
    count.merge(val, 1, Integer::sum);
    countToStack.putIfAbsent(count.get(val), new ArrayDeque<>());
    countToStack.get(count.get(val)).push(val);
    maxFreq = Math.max(maxFreq, count.get(val));
  }

  public int pop() {
    final int val = countToStack.get(maxFreq).pop();
    count.merge(val, -1, Integer::sum);
    if (countToStack.get(maxFreq).isEmpty())
      --maxFreq;
    return val;
  }

  private int maxFreq = 0;
  private Map<Integer, Integer> count = new HashMap<>();
  private Map<Integer, Deque<Integer>> countToStack = new HashMap<>();
}
