class StockSpanner {
  public int next(int price) {
    int span = 1;
    while (!stack.isEmpty() && stack.peek().getKey() <= price)
      span += stack.pop().getValue();
    stack.push(new Pair<>(price, span));
    return span;
  }

  // (price, span)
  private Stack<Pair<Integer, Integer>> stack = new Stack<>();
}
