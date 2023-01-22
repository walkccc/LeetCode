class Logger:
  def __init__(self):
    self.okTime = {}  # {message: ok time}

  def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
    if timestamp < self.okTime.get(message, 0):
      return False

    self.okTime[message] = timestamp + 10
    return True
