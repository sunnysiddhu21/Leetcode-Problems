class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        arr = [0] * k
        count = 0
        sum_mod_k = 0
        
        for num in nums:
            sum_mod_k = (sum_mod_k + num) % k
            sum_mod_k = (sum_mod_k + k) % k  # Handling negative modulo
            arr[sum_mod_k] += 1
        
        count = arr[0]  # Edge case
        
        # nC2 ways to count
        for freq in arr:
            count += (freq * (freq - 1)) // 2
        
        return count
        