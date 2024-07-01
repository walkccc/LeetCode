class MyQueue {
  public void push(int x) {
    input.push(x);
  }

  public int pop() {
    peek();
    return output.pop();
  }

  public int peek() {
    if (output.isEmpty())
      while (!input.isEmpty())
        output.push(input.pop());
    return output.peek();
  }

  public boolean empty() {
    return input.isEmpty() && output.isEmpty();
  }

  private Deque<Integer> input = new ArrayDeque<>();
  private Deque<Integer> output = new ArrayDeque<>();
}
