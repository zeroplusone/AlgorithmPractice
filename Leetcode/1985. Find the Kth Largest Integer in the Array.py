class Solution(object):
    def kthLargestNumber(self, nums, k):
        """
        :type nums: List[str]
        :type k: int
        :rtype: str
        """
        arr=[ int(i) for i in nums]
        arr.sort();
        return str(arr[len(arr)-k])
        
