class Solution:
    def reformatDate(self, date: str) -> str:
        months = {"Jan": "01", "Feb": "02", "Mar": "03", "Apr": "04", "May": "05", "Jun": "06", "Jul" : "07", "Aug": "08", "Sep" : "09", "Oct": "10", "Nov": "11", "Dec" : "12"}
        
        arr = date.split()
        ans = arr[2] + '-' + months[arr[1]] + '-'
        cur = ""
        for x in arr[0]:
            if (x.isdigit()):
                cur += x
        ans += ('' if len(cur) == 2 else '0') + cur
        return ans