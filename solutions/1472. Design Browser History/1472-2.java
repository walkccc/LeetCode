class BrowserHistory {
  public BrowserHistory(String homepage) {
    visit(homepage);
  }

  public void visit(String url) {
    future = new Stack<>();
    history.push(url);
  }

  public String back(int steps) {
    while (steps-- > 0 && history.size() > 1)
      future.push(history.pop());
    return history.peek();
  }

  public String forward(int steps) {
    while (steps-- > 0 && !future.empty())
      history.push(future.pop());
    return history.peek();
  }

  private Stack<String> history = new Stack<>();
  private Stack<String> future;
}
