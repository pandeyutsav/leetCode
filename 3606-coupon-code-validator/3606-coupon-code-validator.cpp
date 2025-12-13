class Solution {
public:
    unordered_set<string> validLine={"electronics","grocery","pharmacy","restaurant"};//valid business lines
    bool validCode(string& code) // helper function to check if all characters in the code are valid
    {
        if(code=="")return false;
        for(char c : code ) if(!((c>='a' && c<='z') || (c>='A' && c<='Z')|| (c>='0' && c<='9') || c=='_')) return false;
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) 
    {
        int n=code.size();
        vector<pair<string,string>> validcodes; 
        for(int i=0;i<n;i++)
        {
            if(isActive[i] && validCode(code[i]) && validLine.find(businessLine[i])!=validLine.end())validcodes.push_back({businessLine[i],code[i]});// if all requirements are met, push the business line and the code to the vector
        }
        sort(validcodes.begin(),validcodes.end());
        vector<string> ans;
        for(pair<string,string>& vc : validcodes)ans.push_back(vc.second);
        return ans;
    }
};