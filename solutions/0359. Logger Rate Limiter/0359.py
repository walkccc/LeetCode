class Logger:
  def __init__(self):
    self.okTime = {}

  def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
    """
    Returns true if the message should be printed in the given timestamp, otherwise returns false.
    If this method returns false, the message will not be printed.
    The timestamp is in seconds granularity.
    """
    if timestamp < self.okTime.get(message, 0):
      return False

    self.okTime[message] = timestamp + 10
    return True
