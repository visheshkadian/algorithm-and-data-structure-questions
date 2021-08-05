/*
Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.

link:https://leetcode.com/problems/maximum-number-of-words-you-can-type/

*/
class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        
        //store the current broken letters  in an array 
        vector<int> freq(26,0);
        for(int i=0;i<broken.length();i++)
            freq[broken[i]-'a']++;
        
        //stores if the current word in text is broken or not
        bool isBroken=false;
        //the words which we can type
        int count=0;
        for(int i=0;i<text.length();i++)
        {
            if(text[i]==' ')
            {
                //the previous can be typed
                if(!isBroken)
                    count++;
                isBroken=false;
                
            }
            else{
                //if the word contains a broken letter mark isBroken=true
                if(freq[text[i]-'a']!=0)
                    isBroken=true;
            }
        }
        //for the last word in text
        if(!isBroken)
            count++;
        return count;
    }
};