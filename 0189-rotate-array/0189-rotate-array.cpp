class Solution {
public:

    void reverse(vector<int>& nums, int start,int end){
        int n = nums.size();
        int low = start;
        int high = end;
        while(low<high){
            swap(nums[low],nums[high]);
            high--;
            low++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        int m = k%n;

        reverse(nums,0,n-m-1);
        reverse(nums,n-m,n-1);
        reverse(nums,0,n-1);
        return;

        
    }
};