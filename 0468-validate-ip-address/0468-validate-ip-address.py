class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def token4(s):
            if not s: return False
            for x in s:
                if not x.isdigit():
                    return False
            if s and (int(s) > 255 or int(s) < 0):
                return False
            if len(s) > 1 and s[0] == '0':
                return False
            return True
        
        def token6(s):
            if not s: return False
            if not (1 <= len(s) <= 4):
                return False
            for x in s:
                if not x.isdigit() and (x.lower() < 'a' or x.lower() > 'f'):
                    return False
            return True
        
        def isIPv4(ip):
            arr = list(ip.split('.'))
            if len(arr) != 4:
                return False
            for i in range(4):
                if not token4(arr[i]):
                    return False
            return True
        
        def isIPv6(ip):
            arr = list(ip.split(':'))
            if len(arr) != 8:
                return False
            for i in range(8):
                if not token6(arr[i]):
                    return False
            return True
        
        if isIPv4(queryIP):
            return "IPv4"
        if isIPv6(queryIP):
            return "IPv6"
        return "Neither"
            