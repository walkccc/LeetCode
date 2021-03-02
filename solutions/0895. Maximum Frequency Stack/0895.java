class FreqStack {
  public void push(int x) {
    count.put(x, count.getOrDefault(x, 0) + 1);
    maxFreq = Math.max(maxFreq, count.get(x));
    if (!countToStack.containsKey(count.get(x)))
      countToStack.put(count.get(x), new Stack<>());
    countToStack.get(count.get(x)).add(x);
  }

  public int pop() {
    int value = countToStack.get(maxFreq).pop();
    count.put(value, count.get(value) - 1);
    if (countToStack.get(maxFreq).isEmpty())
      --maxFreq;
    return value;
  }

  private int maxFreq = 0;
  private Map<Integer, Integer> count = new HashMap<>();
  private Map<Integer, Stack<Integer>> countToStack = new HashMap<>();
}
