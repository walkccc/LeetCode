class Logger:
  def __init__(self):
    # [(timestamp, message)]
    self.messageQueue = collections.deque()
    self.messageSet = set()

  def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
    # Remove the messages that are 10 seconds from the current timestamp.
    while self.messageQueue:
      headTimestamp, headMessage = self.messageQueue[0]
      if timestamp < headTimestamp + 10:
        break
      self.messageQueue.popleft()
      self.messageSet.remove(headMessage)

    if message in self.messageSet:
      return False

    self.messageQueue.append((timestamp, message))
    self.messageSet.add(message)
    return True
