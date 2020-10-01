class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        ans = set()
        nameToTransactions = collections.defaultdict(list)

        for transaction in transactions:
            name, time, amount, city = transaction.split(',')
            time, amount = int(time), int(amount)
            nameToTransactions[name].append({'time': time, 'city': city})

        for transaction in transactions:
            name, time, amount, city = transaction.split(',')
            time, amount = int(time), int(amount)
            if amount > 1000:
                ans.add(transaction)
            elif name in nameToTransactions:
                for sameName in nameToTransactions[name]:
                    if 0 <= abs(sameName['time'] - time) <= 60 and sameName['city'] != city:
                        ans.add(transaction)

        return ans
