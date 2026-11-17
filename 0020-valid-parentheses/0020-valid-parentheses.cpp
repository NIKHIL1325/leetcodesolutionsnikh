class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(int i =0;i<s.size();i++){
            if((s[i] == '{' )|| (s[i] == '(') || (s[i] == '[')){
                st.push(s[i]);
            }
                else{

            if(st.empty()){
                return false;
            }
            char king = st.top();
        
            if((s[i] == '}' && king == '{') || (s[i] == ']' && king == '[') || (s[i] == ')' && king == '(')){
               st.pop();
            }
            else {
                return false;
            }
            }
        }

        return st.empty();
        
    }
};