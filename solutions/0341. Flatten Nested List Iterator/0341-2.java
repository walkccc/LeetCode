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

  // AddInteger([1, [4, [6]]]) -> stack = [[4, [6]], 1]
  // AddInteger([4, [6]]) -> stack = [[6], 4]
  // AddInteger([6]) -> stack = [6]
  private void addInteger(final List<NestedInteger> nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i)
      stack.push(nestedList.get(i));
  }
}
