/* LC 692
 * Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string,int>> res;
        int n = words.size();
        unordered_map<string,int> m;
        auto cmp = [](pair<string,int> &a, pair<string,int> &b){return (a.second > b.second) || (a.second == b.second && a.first < b.first);};
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> min_heap(cmp);
        for(int i = 0 ; i < n; i++){
            m[words[i]]++;
        }
        
        for(auto p : m){
            min_heap.push(p);
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        
        while(!min_heap.empty()){       
            res.push_back(min_heap.top());
            min_heap.pop();
        }
        sort(res.begin(),res.end(),[](pair<string,int> a, pair<string,int> b){return a.second > b.second || (a.second == b.second && a.first < b.first);});
        
        vector<string> result;
        for(auto p : res) {
            result.push_back(p.first);
        }
        
        return result;
    }
};

/* Tested.
 * Time complexity: O(nlogk)
 * Space complexity: O(n)
 */
