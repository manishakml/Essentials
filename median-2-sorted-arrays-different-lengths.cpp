/* LC 4
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 */
 
 class Solution {
public:
    double med(vector<int>::iterator nums1, int m){
        if(m==0) return -1;
        if(m&1){
            return nums1[m/2];
        } 
        return (nums1[m/2]+nums1[m/2 -1])/2.0;       
    }
    
    double med2(int a, int b){
        return (a+b)/2.0;
    }
    
    double med3(int a, int b, int c){
        return a+b+c -max(a,max(b,c)) -min(a,min(b,c));
    }
    
    double med4(int a, int b, int c, int d) {
        int M = max(a,max(b,max(c,d)));
        int m = min(a,min(b,min(c,d)));
        return (a+b+c+d -M -m )/2.0;
    }
    
    double median_util(vector<int>::iterator nums1, int n, vector<int>::iterator nums2, int m) {
        if(n==0) {
            return med(nums2,m);
        }
        
        if(n==1){
            if(m==1){
                return med2(nums1[0],nums2[0]);
            }
            if(m&1){
                return med2(nums2[m/2],med3(nums2[m/2 -1],nums2[m/2 +1],nums1[0]));
            }
            return med3(nums1[0],nums2[m/2],nums2[m/2 -1]);
        }
        
        if(n==2){
            if(m==2){
                return med4(nums1[0],nums1[1],nums2[0],nums2[1]);
            }
            if(m&1){
                return med3(nums2[m/2],max(nums1[0],nums2[m/2 -1]), min(nums1[1],nums2[m/2 +1]));
            }
            return med4(nums2[m/2],nums2[m/2 -1],max(nums1[0],nums2[m/2 -2]), min(nums1[1],nums2[m/2 +1]));
        }
        
        int idx1 = (n-1)/2;
        int idx2 = (m-1)/2;
        
        if(nums1[idx1] > nums2[idx2]) {
            return median_util(nums1, n/2+1, nums2+idx1, m-idx1);
        }
        return median_util(nums1+idx1, n/2+1, nums2, m-idx1);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m) {
            swap(n,m);
            swap(nums1,nums2);
        }
        
        return median_util(nums1.begin(),n,nums2.begin(),m);
    }
};

/* Tested.
 * Time complexity: O(log(m+n)) where m and n are 2 lengths of arrays.
 * Space complexity: O(1).
 */
