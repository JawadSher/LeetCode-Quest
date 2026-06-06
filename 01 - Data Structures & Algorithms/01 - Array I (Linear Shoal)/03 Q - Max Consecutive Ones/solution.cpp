class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev = 0;
        int curr = 0;

        for(int i = 0; i < nums.size(); i++){
           if(nums[i] == 1) {
            curr++;
           }else{
            prev = max(prev, curr);
            curr = 0;
           }
        }

        return max(prev, curr);
    }
};
