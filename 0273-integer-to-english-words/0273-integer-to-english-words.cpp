class Solution {
public:
//     vector<pair<int, string>> mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, 
//         {100, "Hundred"},   {90, "Ninety"},{80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, 
//         {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},  {20, "Twenty"},  {19, "Nineteen"},
//         {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"},{15, "Fifteen"},{14, "Fourteen"},
//         {13, "Thirteen"},{12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"},  {8, "Eight"},
//         {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};
    
    map<int, string> mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, 
        {100, "Hundred"},   {90, "Ninety"},{80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, 
        {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},  {20, "Twenty"},  {19, "Nineteen"},
        {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"},{15, "Fifteen"},{14, "Fourteen"},
        {13, "Thirteen"},{12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"},  {8, "Eight"},
        {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};
    
    
    string numberToWords(int num) {
        /*
        if (num > 1000) map[num / 1000];
        elif (num > 100) map[num / 100];
        else map[num]
        */
        if (num == 0) return "Zero";
        if (num >= 1e9)
            return numberToWords(num / 1e9) + " Billion" + (num % (int)1e9 == 0 ? "" : " " + numberToWords(num % (int)1e9));
        if (num >= 1e6)
            return numberToWords(num / 1e6) + " Million" + (num % (int)1e6 == 0 ? "" : " " + numberToWords(num % (int)1e6));
        if (num >= 1000)
            return numberToWords(num / 1000) + " Thousand" + (num % 1000 == 0 ? "" : " " + numberToWords(num % 1000));
        if (num >= 100)
            return numberToWords(num / 100) + " Hundred" + (num % 100 == 0 ? "" : " " + numberToWords(num % 100)) ;
        if (num >= 20)
            return mp[(num / 10) * 10] + (num % 10 == 0 ? "" : " " + numberToWords(num % 10));
        return mp[num];
    }
};