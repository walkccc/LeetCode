public class NestedIterator implements Iterator<Integer> {
  public NestedIterator(List<NestedInteger> nestedList) {
    addInteger(nestedList);
  }

  @Override
  public Integer next() {
    return stack.pop().getInteger();
  }

  @Override
  public boolean hasNext() {
    while (!stack.isEmpty() && !stack.peek().isInteger()) {
      final NestedInteger ni = stack.pop();
      addInteger(ni.getList());
    }
    return !stack.isEmpty();
  }

  private Deque<NestedInteger> stack = new ArrayDeque<>();

  // addInteger([1, [4, [6]]]) -> stack = [[4, [6]], 1]
  // addInteger([4, [6]]) -> stack = [[6], 4]
  // addInteger([6]) -> stack = [6]
  private void addInteger(final List<NestedInteger> nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i)
      stack.push(nestedList.get(i));
  }
}
