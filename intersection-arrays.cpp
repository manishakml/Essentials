/* LC 349
 * Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

//approach 1 - sort and process duplicates while iterating
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while(i < n && j < m){
            if(nums1[i] == nums2[j] && (out.size() == 0 || out.back() != nums1[i] )) {
                out.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]){
                i++;
            } else {
                j++;
            }
        }
        return out;
    }
};

//approach 2 - extra storage
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        set<int> s(nums1.begin(),nums1.end());
        for(int n: nums2){
            if(s.count(n)){
                s.erase(n);
                out.push_back(n);
            }
        }
        return out;
    }
};
