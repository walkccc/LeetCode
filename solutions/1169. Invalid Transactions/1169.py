class Solution:
  def invalidTransactions(self, transactions: List[str]) -> List[str]:
    ans = []
    nameToTranses = collections.defaultdict(list)

    for t in transactions:
      name, time, amount, city = t.split(',')
      time, amount = int(time), int(amount)
      nameToTranses[name].append({'time': time, 'city': city})

    for t in transactions:
      name, time, amount, city = t.split(',')
      time, amount = int(time), int(amount)
      if amount > 1000:
        ans.append(t)
      elif name in nameToTranses:
        for sameName in nameToTranses[name]:
          if abs(sameName['time'] - time) <= 60 and sameName['city'] != city:
            ans.append(t)
            break

    return ans
