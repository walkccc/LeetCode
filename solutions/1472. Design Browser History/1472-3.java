class Node {
  public Node prev;
  public Node next;
  public final String url;
  public Node(final String url) {
    this.url = url;
  }
}

class BrowserHistory {
  public BrowserHistory(String homepage) {
    curr = new Node(homepage);
  }

  public void visit(String url) {
    curr.next = new Node(url);
    curr.next.prev = curr;
    curr = curr.next;
  }

  public String back(int steps) {
    while (curr.prev != null && steps-- > 0)
      curr = curr.prev;
    return curr.url;
  }

  public String forward(int steps) {
    while (curr.next != null && steps-- > 0)
      curr = curr.next;
    return curr.url;
  }

  private Node curr;
}
