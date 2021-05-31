// leetcode 1

// Hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++)
        {
          
           if(um.find(target-nums[i]) != um.end())
               return {um[target-nums[i]], i};
            um[nums[i]] = i;
        }
        return {};
    }
};


// Two Pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int i = 0;
        int j = sorted.size()-1;
        for(i=0;i<sorted.size();i++)
        {
            int sum = sorted[i]+sorted[j];
             cout << i<<" "<<j <<" "<<sum<<endl;
            if(sum == target)
                break;
            else if(sum > target)
            {
                j--;  
                i--;
            }
                   
        }
        vector<int> res;
        for(int k=0;k<nums.size();k++)
            if(nums[k] == sorted[i] || nums[k] == sorted[j])
                res.push_back(k);
    
       
        return res;
    }
};
