#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        
        // Calculate prefix products
        vector<int> prefixProducts(n);
        prefixProducts[0] = 1;
        for (int i = 1; i < n; ++i) {
            prefixProducts[i] = prefixProducts[i - 1] * nums[i - 1];
        }
        
        // Calculate suffix products and multiply with prefix products to get answer
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] = prefixProducts[i] * suffixProduct;
            suffixProduct *= nums[i];
        }
        
        return answer;
    }
};