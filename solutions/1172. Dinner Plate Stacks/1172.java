class DinnerPlates {
  public DinnerPlates(int capacity) {
    this.capacity = capacity;
    minHeap.offer(0);
  }

  public void push(int val) {
    final int index = minHeap.peek();
    // add new stack on demand
    if (index == stacks.size())
      stacks.add(new ArrayDeque<>());
    // push the new value
    stacks.get(index).push(val);
    // if the stack pushed is full, remove its candidacy from minHeap
    if (stacks.get(index).size() == capacity) {
      minHeap.poll();
      // if minHeap is empty, the next available stack index is stacks.size()
      if (minHeap.isEmpty())
        minHeap.offer(stacks.size());
    }
  }

  public int pop() {
    // remove empty stacks from back
    while (!stacks.isEmpty() && stacks.get(stacks.size() - 1).isEmpty())
      stacks.remove(stacks.size() - 1);
    if (stacks.isEmpty())
      return -1;
    return popAtStack(stacks.size() - 1);
  }

  public int popAtStack(int index) {
    if (index >= stacks.size() || stacks.get(index).isEmpty())
      return -1;
    // if the stack is going to have space, add its candiday to minHeap
    if (stacks.get(index).size() == capacity)
      minHeap.offer(index);
    return stacks.get(index).pop();
  }

  private final int capacity;
  private List<Deque<Integer>> stacks = new ArrayList<>();
  private Queue<Integer> minHeap = new PriorityQueue<>();
}
