class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        int low =0;
        int n = a.size();
        int high = n-1;
     
        while(low<=high){
               int mid = low + (high - low )/2;
            if(a[mid]==target){
                return mid;
            }
           else if(a[mid]<target){
            low = mid+1;
        }else{
            high = mid-1;
        }
        }
        return low ;
        
    }
};