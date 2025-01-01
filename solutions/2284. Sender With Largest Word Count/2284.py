class Solution:
  def largestWordCount(self, messages: list[str], senders: list[str]) -> str:
    n = len(messages)
    ans = ''
    maxWordsSent = 0
    count = collections.Counter()  # [sender, # Words sent]

    for message, sender in zip(messages, senders):
      wordsCount = message.count(' ') + 1
      count[sender] += wordsCount
      numWordsSent = count[sender]
      if numWordsSent > maxWordsSent:
        ans = sender
        maxWordsSent = numWordsSent
      elif numWordsSent == maxWordsSent and sender > ans:
        ans = sender

    return ans
