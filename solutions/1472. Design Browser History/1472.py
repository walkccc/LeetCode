class BrowserHistory:
  def __init__(self, homepage: str):
    self.urls = []
    self.index = -1
    self.lastIndex = -1
    self.visit(homepage)

  def visit(self, url: str) -> None:
    self.index += 1
    if self.index < len(self.urls):
      self.urls[self.index] = url
    else:
      self.urls.append(url)
    self.lastIndex = self.index

  def back(self, steps: int) -> str:
    self.index = max(0, self.index - steps)
    return self.urls[self.index]

  def forward(self, steps: int) -> str:
    self.index = min(self.lastIndex, self.index + steps)
    return self.urls[self.index]
