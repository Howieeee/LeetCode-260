class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        int num1 = nums[0] , num2 = nums[1];
       
        if(nums.size()==2 ){
            ans.push_back(num1); ans.push_back(num2);
            return ans;
        }
        
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                if(nums[i] != ans[1])
                    ans.push_back(nums[i]);
                return ans;
            }
            //0,1,1,2
            if(nums[i] == nums[i+1]){// 1,2,2,3,4,4,5,5
                if(!ans.empty() && ans[ans.size()-1] == nums[i])
                    ans.pop_back();
                
                if(ans.size() ==2)
                    break;
                i++;
            }else{
                if(ans.size()==2)
                    break;
                ans.push_back(nums[i]);
                ans.push_back(nums[i+1]);
                
            }
        }
        
        return ans;
    }
};
