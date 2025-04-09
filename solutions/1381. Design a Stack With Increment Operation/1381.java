class CustomStack {
  public CustomStack(int maxSize) {
    this.maxSize = maxSize;
  }

  public void push(int x) {
    if (stack.size() == maxSize)
      return;
    stack.push(x);
    pendingIncrements.add(0);
  }

  public int pop() {
    if (stack.isEmpty())
      return -1;
    final int i = stack.size() - 1;
    final int pendingIncrement = pendingIncrements.get(i);
    pendingIncrements.remove(i);
    if (i > 0)
      pendingIncrements.set(i - 1, pendingIncrements.get(i - 1) + pendingIncrement);
    return stack.pop() + pendingIncrement;
  }

  public void increment(int k, int val) {
    if (stack.isEmpty())
      return;
    final int i = Math.min(k - 1, stack.size() - 1);
    pendingIncrements.set(i, pendingIncrements.get(i) + val);
  }

  private int maxSize;
  private Deque<Integer> stack = new ArrayDeque<>();
  // pendingIncrements[i] := the pending increment for stack[0..i].
  private List<Integer> pendingIncrements = new ArrayList<>();
}
