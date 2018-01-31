/* LC 68
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 * Return the formatted lines as:
 * [
   "This    is    an",
   "example  of text",
   "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 */
 class Solution {
public:
    void formLine(int i, int j, int left, vector<string> &res, vector<string> &words, bool &last_line) {
        int legit_spaces = j-i;
        //legit + illegit
        int total_spaces = legit_spaces+left;
        int equal_space = 0;
        int unequal_space = 0;
        bool one_word = false;
        //to avoid /0 condition
        if(legit_spaces && !last_line) {
            //to be equally divided in the gaps
            equal_space = total_spaces/legit_spaces;
            //Remaining spaces (== left) which will be < legit_spaces and be distributed as we iterate
            unequal_space = total_spaces%legit_spaces;
        } else if (!legit_spaces){
            // Special handling for one word line
            one_word = true;
        }
        
        string s = "";
        for(int k = i; k <= j; k++) {
            s += words[k];
            //If there is a next word in the line
            if(legit_spaces && !last_line) {
                int e = equal_space;
                //distribute the equal spaces
                while(e) {
                    s += " ";
                    e--;
                }
                //Unequal will always be < legit_spaces ( We used a modulo). So, sufficient to distribute 1 space per gap.
                if(unequal_space) {
                    s += " ";
                    unequal_space--;
                }
                legit_spaces--;
            } else if(one_word) {
                // Add all spaces after the word if that's the only word on the line
                while(total_spaces) {
                    s += " ";
                    total_spaces--;
                }
            } else if(last_line){
                s += " ";
                total_spaces--;
            }
        }
        if(last_line) {
            while(total_spaces) {
                s += " ";
                total_spaces--;
            }
        }
        res.push_back(s);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int start = 0;
        if(maxWidth < 0){
            return res;
        }
        int left = maxWidth;
        int i = 0;
        //last line flag - special handling
        bool ll_flag = false;
        // convert sizes to int
        int N = words.size();
        if(!N) return res;        
        while(i < N){
            int n = words[i].size();
            // Compute the number of spaces left for one line            
            //compare int with int; comparing int with size_t does not fare well with -ve numbers.
            while(i < N && n <= left) {
                left -= (n + 1);  // Include the legit space in the calculation
                i++;
                //compute next word's length
                n = words[i].size();
            }
            // exclude the last legit space added, hence left+1. We want "This    is", not "This     is ". So, left contains only illegitimate spaces.
            if(i-1 == N-1) {
                ll_flag = true;
            }
            formLine(start, i-1, left+1, res, words, ll_flag);
            //Reset start and left for next line
            start = i;
            left = maxWidth;
        }
        return res;
    }
};

/* Tested.
 * Note: This problem has lot of minute calculations and it is easy to go 1-off. Also, note the differntial handling for last line and one-word cases.
 * Time complexity: O(N) where N is the number of words.
 * Space complexity: O(1) for computation. However, depending on the input, the number of padded spaces might be huge and an overkill.
 */
