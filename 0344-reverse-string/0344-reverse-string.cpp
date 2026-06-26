class Solution {
public:
    void reverseString(vector<char>& str) {
        int st=0;
        int end = str.size()-1;

        while(st <= end) {
            swap(str[st], str[end]);
            st++;
            end--;
        }
    }
};