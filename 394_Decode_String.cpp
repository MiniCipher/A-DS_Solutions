class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=']')
            st.push(s[i]);
            else
            {
                string temp="";
                while(st.top()!='[')
                {
                    temp+=st.top();
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                st.pop();

                string num="";
                while(st.empty()==false && isdigit(st.top()))
                {
                    num+=st.top();
                    st.pop();
                }
                if(num.size()>0)
                {
                    reverse(num.begin(),num.end());
                    int n = stoi(num);
                    while(n>0)
                    {
                        for(int j=0;j<temp.size();j++)
                        {
                            st.push(temp[j]);
                        }
                        n--;
                    }
                }
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
