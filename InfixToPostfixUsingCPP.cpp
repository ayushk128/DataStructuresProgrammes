#include<bits/stdc++.h>
using namespace std;
bool Operator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/')
        return true;
    else 
        return false;
}
int precedance(char a){
    if(a == '*' || a == '/')
        return 3;
    else if(a == '+' || a == '-')
        return 2;
    else
        return 0;
}
string InfixToPostfix(string infix){
    stack<char> s;
    s.push('$');
    string postfix;
    int i = 0;
    while(infix[i] != '\0'){
        if(!Operator(infix[i])){
            postfix+=infix[i];
            i++;
        }
        else{
            if(precedance(infix[i]) > precedance(s.top())){
                s.push(infix[i]);
                i++;
            }
            else{
                char ch = s.top();
                s.pop();
                postfix+=ch;
            }
        }
    }
    while(s.top()!='$'){
        char c = s.top();
        s.pop();
        postfix+=c;
    }

    return postfix;
}
int main(){
    string infix = "a-b+t/d";
    // cout<<"Enter the string:";
    // cin>>infix;
    string postfix = InfixToPostfix(infix);
    cout<<postfix<<"\n";
}