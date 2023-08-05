class Solution 
{
public:
    bool isNumber(string s)
    {
        bool digitSeen=false,dotSeen=false,eSeen=false;
        int plusMinus=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]-'0'>=0 && s[i]-'0'<=9)
            {
                digitSeen=true;
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                if(plusMinus==2 || (i>0 && (s[i-1]!='e' && s[i-1]!='E')) || i==n-1)
                {
                    return false;
                }
                plusMinus++;
            }
            else if(s[i]=='e' || s[i]=='E')
            {
                if(eSeen || !digitSeen || i==n-1)
                {
                    return false;
                }
                eSeen=true;
            }
            else if(s[i]=='.')
            {
                if(eSeen || dotSeen || (i==n-1 && !digitSeen))
                {
                    return false;
                }
                dotSeen=true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }









};
