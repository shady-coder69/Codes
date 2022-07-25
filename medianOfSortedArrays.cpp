class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n2<n1)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = (n1+n2+1)/2;
        int l1,l2,r1,r2;
        int l=0,r=n1;
        while(l <= r) {
            int cut1 = (l+r)/2;
            int cut2 = n-cut1;
            l1 = (cut1 != 0)? nums1[cut1-1]: INT_MIN;
            l2 = (cut2 != 0)? nums2[cut2-1]: INT_MIN;
            r1 = cut1!=n1? nums1[cut1]: INT_MAX;
            r2 = cut2!=n2? nums2[cut2]: INT_MAX;
            if(l1 <= r2 and l2 <= r1) {
                if((n1+n2+1)%2 == 0)
                    return max(l1, l2);
                else
                    return ((max(l1, l2) + min(r1, r2))/2.0);
            }   
            else {
                if(l1 > r2)
                    r = cut1-1;
                else if(l2 > r1)
                    l = cut1+1;  
            }
        }
        return 0;
    }
};
