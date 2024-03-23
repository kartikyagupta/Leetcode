#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        // Count the occurrences of each character in s
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        
        string result;
        
        // Append characters from s in the order specified by order
        for (char c : order) {
            if (freq.find(c) != freq.end()) {
                result.append(freq[c], c);
                freq.erase(c);
            }
        }
        
        // Append any remaining characters from s
        for (auto& pair : freq) {
            result.append(pair.second, pair.first);
        }
        
        return result;
    }
};
