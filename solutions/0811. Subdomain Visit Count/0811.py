class Solution:
  def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
    ans = []
    count = Counter()

    for cpdomain in cpdomains:
      num, domains = cpdomain.split()
      num, domains = int(num), domains.split('.')
      for i in range(len(domains))[::-1]:
        count['.'.join(domains[i:])] += num

    return [str(freq) + ' ' + domain for domain, freq in count.items()]
