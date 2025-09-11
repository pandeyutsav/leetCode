class Solution {
public:
    string sortVowels(string s) {
        vector<int>upper(26,0);
        vector<int>lower(26,0);
        string ans;
        int index=0,count=0;
        while(index<s.size())
        {
            if(s[index]=='a'||s[index]=='e'||s[index]=='i'||s[index]=='o'||s[index]=='u')
            {
                lower[s[index]-'a']++;
                s[index]='#';
            }
            else if(s[index]=='A'||s[index]=='E'||s[index]=='I'||s[index]=='O'||s[index]=='U')
            {
                upper[s[index]-'A']++;
                s[index]='#';
            }
            index++;
        }
        for(int i=0;i<26;i++)
        {
            char ch=i+'A';
            while(upper[i])
            {
                ans+=ch;
                upper[i]--;
            }
        }
        for(int i=0;i<26;i++)
        {
            char ch=i+'a';
            while(lower[i])
            {
                ans+=ch;
                lower[i]--;
            }
        }
        int first=0,second=0;
        while(second<ans.size())
        {
            if(s[first]=='#')
            {
                s[first]=ans[second];
                second++;
            }
            first++;
        }
return s;
    }
};