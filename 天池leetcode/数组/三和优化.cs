public class Solution{
    public int TreeSumClose(int[] nums,int target){
        nums =nums.OrderBy(a => a).ToArray();
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0;i < nums.Length;i++){
            int start = i+1,end = nums.Length-1;
            while(start < end){
                int sum = nums[start] + nums[end] + nums[i];
                if(Math.Abs(target - sum) < Math.Abs(target - result))
                    return sum;
                if(sum > target)
                    end--;
                else if(sum < target)
                    start++;
                else
                    return result;
            }
        }
        return result;
    }
}
