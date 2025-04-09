class BrowserHistory:
  def __init__(self, homepage: str):
    self.history = []
    self.visit(homepage)

  def visit(self, url: str) -> None:
    self.history.append(url)
    self.future = []

  def back(self, steps: int) -> str:
    while len(self.history) > 1 and steps > 0:
      self.future.append(self.history.pop())
      steps -= 1
    return self.history[-1]

  def forward(self, steps: int) -> str:
    while self.future and steps > 0:
      self.history.append(self.future.pop())
      steps -= 1
    return self.history[-1]
