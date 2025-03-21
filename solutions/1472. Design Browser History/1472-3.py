class Node:
  def __init__(self, url: str):
    self.prev = None
    self.next = None
    self.url = url


class BrowserHistory:
  def __init__(self, homepage: str):
    self.curr = Node(homepage)

  def visit(self, url: str) -> None:
    self.curr.next = Node(url)
    self.curr.next.prev = self.curr
    self.curr = self.curr.next

  def back(self, steps: int) -> str:
    while self.curr.prev and steps > 0:
      self.curr = self.curr.prev
      steps -= 1
    return self.curr.url

  def forward(self, steps: int) -> str:
    while self.curr.next and steps > 0:
      self.curr = self.curr.next
      steps -= 1
    return self.curr.url
