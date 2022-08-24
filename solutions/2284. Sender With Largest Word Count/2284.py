class Solution:
  def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
    n = len(messages)
    ans = ''
    maxWordsSent = 0
    count = Counter()  # [sender, # words sent]

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
