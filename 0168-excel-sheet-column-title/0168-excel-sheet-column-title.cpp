class Solution {
public:
    string convertToTitle(int columnNumber) {
        string col;
        int rem;

        while(columnNumber){
            rem = (--columnNumber) % 26;
            columnNumber /= 26;
            col = char('A' + rem) + col;
        }

        return col;
    }
};