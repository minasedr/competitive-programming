class Solution {
public:
    string strip(string inpt) {
        auto start = inpt.begin();
        auto end = inpt.rbegin();
        while (isspace(*start))
            start++;
        while (isspace(*end))
            end++;
        return string(start, end.base());
    }
    
    string reformatDate(string date) {
        map<string,string> month = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, 
                                    {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, 
                                    {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, 
                                    {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        
        int n = date.size();
        string ans;
        
        ans += date.substr(n - 4, 4) + "-";
        ans += month[strip(date.substr(4, 4))] + "-";
        ans += isdigit(date[1]) ? date.substr(0, 2) : "0" + string(1, date[0]);
        return ans;
    }
};