class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       vector<int> shuffle;
        
        int j = n;
        for(int i = 0; i < n; i++){
            shuffle.push_back(nums[i]);
            shuffle.push_back(nums[j]);
            j++;
        }
        
        return shuffle;
    }
};
