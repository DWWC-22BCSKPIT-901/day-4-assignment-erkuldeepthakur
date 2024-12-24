#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  
    stack<int> s;  
    
   
    for (int i = 0; i < 2 * n; ++i) {
        int currentIndex = i % n;  
        while (!s.empty() && nums[s.top()] < nums[currentIndex]) {
            int index = s.top();
            s.pop();
            result[index] = nums[currentIndex];  
        }
        if (i < n) {  
            s.push(i);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 1};
    vector<int> result1 = nextGreaterElements(nums1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;  
    
    vector<int> nums2 = {1, 2, 3, 4, 3};
    vector<int> result2 = nextGreaterElements(nums2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;  

    return 0;
}
