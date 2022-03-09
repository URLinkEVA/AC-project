class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        if not cpdomains:
            return []
        
        res = {}
        for case in cpdomains:
            time, domain = case.split()     # split函数可以指定最大切割次数
            length = len(domain.split('.'))
            for num in range(length):
                dm = domain.split('.', num)[-1]
                res[dm] = res.get(dm, 0) + int(time)
        return [str(v)+' '+k for k, v in res.items()]
