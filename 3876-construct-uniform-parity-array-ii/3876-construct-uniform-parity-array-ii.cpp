class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();
        vector<int> nums2(n);

        int min_num = nums1[0];

        for(int i = 0; i < n; i++){
            min_num = min(min_num, nums1[i]);
        }

        for(int i = 0; i < n; i++){
            nums2[i] = nums1[i];

            if(nums1[i] % 2 != min_num % 2){
                if(min_num % 2 == 1){
                    nums2[i] = nums1[i] - min_num;
                }
            }
        }

        for(int i = 1; i < n; i++){
            if(nums2[i] % 2 != nums2[0] % 2){
                return false;
            }
        }

        return true;
    }
};