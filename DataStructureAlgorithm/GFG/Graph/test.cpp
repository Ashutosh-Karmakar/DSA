 #include<iostream>
 #include<vector>
 using namespace std;

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int temp;
        // while(i<m){
        //      nums1[i++] = 0;
        // }
        while(i<m && j<n){
            if(nums1[i] > nums2[j]){
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
                j++;
            }
            i++;
        }
        cout << "num1" << endl;
        for(int i:nums1){
            cout << i << " ";
        }
        cout << "num2" << endl;
        for(int i:nums2){
            cout << i << " ";
        }
        i = m;
        int k = 0;
        while(i< nums1.size()){
            nums1[i] = nums2[k];
            i++;
            k++;
        }
    }

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1,3,nums2,3);
//     for(int i:nums1){
//         cout << i << " ";
//     }
//     cout << " After ::" << endl;
//     for(int i:nums1){
//         cout << i << " ";
//     }
}