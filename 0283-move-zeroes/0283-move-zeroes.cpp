class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int boss = 0;
    for(int i =0;i<n;i++){
        if(nums[i]!=0){
            nums[boss] = nums[i];
            boss++;
        }
    }
    while(boss<n){
        nums[boss]=0;
        boss++;
    }
     
    }
};