class Solution { 
public: 
    int jump(vector<int>& nums) { 
 
        int n = nums.size(); 
        int dist = 0; 
        int jump = 0; 
        int end = 0; 

        if(n == 1){ 
            return 0; 
        }
 
        for(int i = 0; i < n-1; i++){ 

            dist = max(dist, nums[i] + i); 
 
            if(i == end){ 
                jump++; 
                end = dist; 
            } 
             
            if(end >= n-1){ 
                return jump; 
            } 
        } 
        
        return -1; 
    } 
};