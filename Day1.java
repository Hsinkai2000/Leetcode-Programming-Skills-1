
class Day1 {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4 };
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
        int[] nums2 = {1,7,3,6,5,6};
        System.out.println("pivot Index: " + pivotIndex(nums2));
    }

    /*
     * Given an array nums. We define a running sum of an array as runningSum[i] =
     * sum(nums[0]…nums[i]).
     * 
     * Return the running sum of nums.
     */
    public static int[] runningSum(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        return nums;
    }

    /*
     * Given an array of integers nums, calculate the pivot index of this array.
     * 
     * The pivot index is the index where the sum of all the numbers strictly to the
     * left of the index is equal to the sum of all the numbers strictly to the
     * index's right.
     * 
     * If the index is on the left edge of the array, then the left sum is 0 because
     * there are no elements to the left. This also applies to the right edge of the
     * array.
     * 
     * Return the leftmost pivot index. If no such index exists, return -1.
     */

    // # Intuition
    // We ned to find the left and right side sum to a certain midpoint and compare them
    // # Approach
    // Finding the sum of index 1 thru N will allow us to know the maximum sum of the right side. From there, we just need to loop through the array from the left and increase the left sum by nums[midpoint-1] while decreasing the right sum by the nums[midpoint]
    // # Complexity
    // - Time complexity: O(n) *only looped through left and right side once O(2n) -> O(n)

    // # Code
    // ```
    public static int pivotIndex(int[] nums) {
        int result = 0; //plainly for return purposes only (try to remove if you can)    
        int left = 0; 
        int right = 0;
        //loop backwards through nums[n...1] to find max sum of right side 
        for (int r = nums.length-1; r > 0; r--) {
            right += nums[r];
        }
        //loop through left side to compare Sums
        for (int l = 0; l < nums.length; l++) {   
            /* When sum of right side != 0, increase left sum by current l-1 (due to excluding the midpoint index)
            and decreasing right sum by l (due to movement of midpoint index). */
            if(l!=0){
                left += nums[l-1];
                right -= nums[l];
            }         
            //If left and right sum are the same, return the midpoint index in our case, l. 
            //This handles when midpoint is index 0 as it instantly gets into this conditional statement when l is 0
            if(left==right){
                result = l;
                break;
            }
            //If does not exist
            else{
                result = -1;
            }
        }
        return result;
    }
}