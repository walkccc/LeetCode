class BrowserHistory:
  def __init__(self, homepage: str):
    self.history = []
    self.visit(homepage)

  def visit(self, url: str) -> None:
    self.future = []
    self.history.append(url)

  def back(self, steps: int) -> str:
    while steps > 0 and len(self.history) > 1:
      self.future.append(self.history.pop())
      steps -= 1
    return self.history[-1]

  def forward(self, steps: int) -> str:
    while steps > 0 and self.future:
      self.history.append(self.future.pop())
      steps -= 1
    return self.history[-1]
