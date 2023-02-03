class Solution:
    def simplifyPath(self, path: str) -> str:
        arr, cur = [], ''
        
        for ch in path + '/':
            if ch == '/':
                if cur == '..':
                    if arr: arr.pop()
                elif cur != '' and cur != '.':
                    arr.append(cur)
                cur = ''
            else:
                cur += ch
        return '/' + '/'.join(arr)