from collections import deque
class Solution:
    def isPalindrome(self, s: str) -> bool:
        char_que = deque()
        for el in s:
            if el.isalnum():
                char_que.append(el.lower())

        len_que = len(char_que)
        for _ in range(len_que//2):
            if char_que.pop() != char_que.popleft():
                return False
        return True



s = Solution()
print(s.isPalindrome("A man, a plan, a canal: Panama"))
