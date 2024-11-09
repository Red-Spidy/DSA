#include <iostream>
#include<stack>
using namespace std;

// Balancing Bracket Waali POroblem
// Jab bhi mujhe closing bracket dikhe mujhe baaar baar ye check krna hai ki uske coorrsponding ka 
// open brackket hai 
// Openeing bracket mtlb mai push kruinga

bool isValid(string s){
    stack<char> st;
    for(int i = 0 ; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch=='{' || ch == '['){
            st.push(ch);
        }
        else{ 
            // Closing bracket
            if(!st.empty()){
                char topch = st.top();
                if(ch == ')' && topch =='('){
                    st.pop();
                }

                else if(ch == ']' && topch =='['){
                    st.pop();
                }

                else if(ch == '}' && topch =='{'){
                    st.pop();
                }
                else{
                    // Brackets not matching
                    return false;
                }

            }

            else{
                return false;
            }
        }

    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s ="({{{()}}})";
    cout<<isValid(s);
    return 0;
}