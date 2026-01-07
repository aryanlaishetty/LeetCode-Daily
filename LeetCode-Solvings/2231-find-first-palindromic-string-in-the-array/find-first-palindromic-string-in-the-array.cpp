class Solution {
public:
    bool isPalindrome(string word) {
        string newWord = word;

        reverse(word.begin(), word.end());

        if(word == newWord) {
            return true;
        } else {
            return false;
        }
    }

    string firstPalindrome(vector<string>& words) {

        for(int i=0; i<words.size(); i++) {
            if(isPalindrome(words[i])) {
                return words[i];
            }
        }    

        return "";
    }
};