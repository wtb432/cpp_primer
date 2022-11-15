#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
unordered_map<char, int> pre = {{'-', 0}, {'+', 0}, {'*', 1}, {'/', 1}, {'^', 2}};
void oper(stack<char> &st, stack<string> &ans, char opera)
{
    while (!st.empty() && pre[st.top()] >= pre[opera])
    {
        char t = st.top();
        st.pop();
        string a = ans.top();
        ans.pop();
        string b = ans.top();
        ans.pop();
        string p = "(" + b + t + a + ")";
        ans.push(p);
    }
    st.push(opera);
}
string AddParentheses(const string &infix)
{
    stack<char> st;
    stack<string> ans;
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (st.empty())
                st.push(infix[i]);
            else
                oper(st, ans, infix[i]);
        }
        else if (infix[i] == '(')
        {
            int j = i;
            while (infix[++j] != ')')
                ;
            string p = infix.substr(i, j - i + 1);
            i = j;
            ans.push(p);
        }
        else
        {
            int j = i;
            while (isdigit(infix[++j]))
                ;
            string p = infix.substr(i, j - i);
            ans.push(p);
            i = j - 1;
        }
    }
    while (ans.size() > 1)
    {
        string a = ans.top();
        ans.pop();
        string b = ans.top();
        ans.pop();
        char t = st.top();
        st.pop();
        string p = "(" + b + t + a + ")";
        ans.push(p);
    }
    string p = ans.top();
    p = p.substr(1, p.size() - 2);
    return p;
}
int main()
{
    string test = "31+23-45*54/(9-6)^4";
    // AddParentheses(test);
    cout << AddParentheses(test) << endl;
    return 0;
}