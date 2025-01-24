class Solution:
  def subdomainVisits(self, cpdomains: list[str]) -> list[str]:
    ans = []
    count = collections.Counter()

    for cpdomain in cpdomains:
      num, domains = cpdomain.split()
      num, domains = int(num), domains.split('.')
      for i in reversed(range(len(domains))):
        count['.'.join(domains[i:])] += num

    return [str(freq) + ' ' + domain for domain, freq in count.items()]
