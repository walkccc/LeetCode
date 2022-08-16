class BrowserHistory {
  public BrowserHistory(String homepage) {
    visit(homepage);
  }

  public void visit(String url) {
    history.push(url);
    future = new ArrayDeque<>();
  }

  public String back(int steps) {
    while (history.size() > 1 && steps-- > 0)
      future.push(history.pop());
    return history.peek();
  }

  public String forward(int steps) {
    while (!future.isEmpty() && steps-- > 0)
      history.push(future.pop());
    return history.peek();
  }

  private Deque<String> history = new ArrayDeque<>();
  private Deque<String> future;
}
