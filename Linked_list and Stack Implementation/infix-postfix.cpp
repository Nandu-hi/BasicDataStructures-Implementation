#include<bits/stdc++.h>
using namespace std;

bool precedence(char a,char b){
    if(a==b) return true;
    if((a=='+' && b=='-') ||(a=='-' && b=='+')) return true;
    else{
        if(b=='/'){
            return true;
        }
        if(b=='*' && a!='/'){
            return true;
        }
    }    
    return false;
}

pair<string,int> infixtopostfix(string s){
    string res="";
    stack<char> opstack;
    stack<int> ans;
    for(auto it:s){
        if(it=='+' || it=='-' || it == '*' || it=='/'){
            if(opstack.empty()){
                opstack.push(it);
            }
            else{
                while(!opstack.empty()&&precedence(it,opstack.top())){
                    res=res+opstack.top();
                    int result=ans.top();
                    ans.pop();
                    if(opstack.top()=='+'){
                        result+=ans.top();
                        ans.pop();
                        ans.push(result);
                    }
                    else if(opstack.top()=='-'){
                        result=ans.top()-result;
                        ans.pop();
                        ans.push((result));
                    }
                    else if(opstack.top()=='*'){
                        result*=ans.top();
                        ans.pop();
                        ans.push(result);
                    }
                    else if(opstack.top()=='/'){
                        result=ans.top()/result;
                        ans.pop();
                        ans.push(result);
                    }
                    opstack.pop();
                }
                opstack.push(it);
            }
        }
        else{
            res=res+it;
            ans.push(it-'0');
        }
    }
    while(!opstack.empty()){
        res=res+opstack.top();
        int result=ans.top();
                    ans.pop();
                    if(opstack.top()=='+'){
                        result+=ans.top();
                        ans.pop();
                        ans.push(result);
                    }
                    else if(opstack.top()=='-'){
                        result=ans.top()-result;
                        ans.pop();
                        ans.push((result));
                    }
                    else if(opstack.top()=='*'){
                        result*=ans.top();
                        ans.pop();
                        ans.push(result);
                    }
                    else if(opstack.top()=='/'){
                        result=ans.top()/result;
                        ans.pop();
                        ans.push(result);
                    }
        opstack.pop();
    }
    return {res,ans.top()};
}


int main(){
    string s= "9*2+3-6/3+6";
    pair<string,int> res=infixtopostfix(s);
            //postfix           resultofexpression
    cout << res.first << " " << res.second << endl;
}
