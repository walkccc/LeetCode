class FrontMiddleBackQueue {
  public void pushFront(int val) {
    frontQueue.offerFirst(val);
    moveFrontToBackIfNeeded();
  }

  public void pushMiddle(int val) {
    if (| frontQueue | == | backQueue |)
      backQueue.offerFirst(val);
    else
      frontQueue.offerLast(val);
  }

  public void pushBack(int val) {
    backQueue.offerLast(val);
    moveBackToFrontIfNeeded();
  }

  public int popFront() {
    if (!frontQueue.isEmpty()) {
      final int x = frontQueue.removeFirst();
      moveBackToFrontIfNeeded();
      return x;
    }
    if (!backQueue.isEmpty())
      return backQueue.pollFirst();
    return -1;
  }

  public int popMiddle() {
    if (frontQueue.isEmpty() && backQueue.isEmpty())
      return -1;
    if (frontQueue.size() + 1 == backQueue.size())
      return backQueue.pollFirst();
    // |frontQueue| == |backQueue|
    return frontQueue.pollLast();
  }

  public int popBack() {
    if (backQueue.isEmpty())
      return -1;
    final int x = backQueue.removeLast();
    moveFrontToBackIfNeeded();
    return x;
  }

  private void moveFrontToBackIfNeeded() {
    if (frontQueue.size() - 1 == backQueue.size())
      backQueue.offerFirst(frontQueue.pollLast());
  }

  private void moveBackToFrontIfNeeded() {
    if (frontQueue.size() + 2 == backQueue.size())
      frontQueue.offerLast(backQueue.pollFirst());
  }

  private Deque<Integer> frontQueue = new ArrayDeque<>();
  private Deque<Integer> backQueue = new ArrayDeque<>();
}
