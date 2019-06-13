//Solution
//Time complexity - O(nm)
//Space complexity - O(m)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> m;       
        for (int i = 0; i < nums2.size(); i++)
            m[nums2[i]] = i;
        
        for (int i = 0; i < nums1.size(); i++) {
            int index = m[nums1[i]] + 1;
            
            while (index < nums2.size() && nums2[index] < nums1[i])
                index++;
            
            if (index == nums2.size())
                ans.push_back(-1);
            else
                ans.push_back(nums2[index]);
        }
        return ans;
    }
};
