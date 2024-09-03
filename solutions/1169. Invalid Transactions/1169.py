class Solution:
  def invalidTransactions(self, transactions: list[str]) -> list[str]:
    ans = []
    nameToTrans = collections.defaultdict(list)

    for t in transactions:
      name, time, amount, city = t.split(',')
      time, amount = int(time), int(amount)
      nameToTrans[name].append({'time': time, 'city': city})

    for t in transactions:
      name, time, amount, city = t.split(',')
      time, amount = int(time), int(amount)
      if amount > 1000:
        ans.append(t)
      elif name in nameToTrans:
        for sameName in nameToTrans[name]:
          if abs(sameName['time'] - time) <= 60 and sameName['city'] != city:
            ans.append(t)
            break

    return ans
