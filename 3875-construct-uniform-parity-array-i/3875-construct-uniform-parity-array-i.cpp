class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();
        vector<int> nums2 (n-1);

        for(int i = 0; i < n-1; i++){
            nums2[i] = nums1[i] - nums1[i+1];
           if(nums2[i] % 2 == 0 || nums2[i] %2 != 0){
            return  true;
           }
        }
        return true;
    }
};