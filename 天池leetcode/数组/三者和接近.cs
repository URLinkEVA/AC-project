public class Solution{
    public int TreeSumClose(int[] nums,int target){
        double error = int.MaxValue;
        int sum = 0;
        for(int i = 0;i < nums.Length-2;i++){
            for(int j = i+1;j < nums.Length-1;j++){
                for(int k = j+1;j < nums.Length;j++){
                    if(Math.Abs(nums[i]+nums[j]+nums[k]-target)<error){
                        sum = nums[i] + nums[j] + nums[k];
                        error = Math.Abs(sum - target);
                    }
                }
            }
        }
        return sum;
    }
}
