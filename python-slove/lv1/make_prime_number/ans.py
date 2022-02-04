# 소수 만들기

prime_list=[True]*3000
end=int(3000**0.5)+1
for i in range(2, end):
  if prime_list[i]:
    for j in range(i+i, 3000, i):
      prime_list[j]=False
prime=[i for i in range(2, 3000) if prime_list[i]]

def dfs(nums, check, depth, hap):
  ans=0
  if depth==3:
    if hap in prime:
      return 1
    return 0
  for i in range(len(nums)):
    if check[i]: continue
    check[i]=True
    ans+=dfs(nums, check, depth+1, hap+nums[i])
    for j in range(i+1, len(nums)):
      check[j]=False
  return ans

def solution(nums):
  check=[False]*len(nums)
  answer = dfs(nums, check, 0, 0)
  return answer

nums=[1,2,3,4]
nums=[1,2,7,6,4]
print(solution(nums))
