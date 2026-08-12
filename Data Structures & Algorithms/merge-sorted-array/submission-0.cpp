class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m - 1;
        int r = n - 1;
        int put = m+n-1;
        while(r >= 0 && l >= 0){
            if(l >= 0 && r>=0 && nums1[l] > nums2[r]){
                nums1[put] = nums1[l];
                l--;
                put--;
            }
            else if(l >= 0 && r>= 0 && nums1[l] <= nums2[r]){
                nums1[put] = nums2[r];
                r--;
                put--;
            }
        }

        while(l>=0){
            nums1[put] = nums1[l];
            l--;
            put--;
        }

        while(r >= 0){
            nums1[put] = nums2[r];
            r--;
            put--;
        }
    }
};