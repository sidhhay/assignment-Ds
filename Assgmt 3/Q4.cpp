#include<iostream>
#include<string>
using namespace std;
class stack{
    public:
    int top;
    char arr[100];
    public:
    stack(){
        top=-1;
    }
void push(char val){
    if(top>=99){
        cout<<"stack is full";
        return;
    }
    top++;
    arr[top]=val;

}
char pop(){
if(isempty()){
    cout<<"empty";
    return 0;
}

return arr[top--];
}
    char peek() {
        if (isempty()) return '\0';
        return arr[top];
    }
bool isempty(){
    return top<0;
}
};
int check(char op){
      if(op=='+'||op=='-') return 1;
        if(op=='*'||op=='/') return 2;
          if(op=='^') return 3;
          return 0;
      

}

void convert(string str,int n){
    stack s;
    char postfix[100];
    int k=0;
    for(int i=0;i<n;i++){
        char ch=str[i];
        if(ch>='A' && ch<='Z'){
            postfix[k]=ch;
            k++;
        }
        else if(ch=='('){
            s.push(ch);
        }
        else if(ch==')'){
            while(!s.isempty() && s.peek()!='('){
                postfix[k++]=s.pop();
               
            }
              if (!s.isempty() && s.peek() == '(')
                s.pop();
        }
        else{
            while(!s.isempty() &&  check(s.peek())>=check(ch)){
                postfix[k++]=s.pop();
                
            }
            s.push(ch);
        }

    }
    while(!s.isempty()){
        postfix[k++]=s.pop();
    }
       
        cout<<"postfix: "<<postfix<<endl;


    }

int main(){
    
    string str;
    cout<<"Enter an infix expression: ";
    cin>>str;
    int n=str.length();
    
    convert(str,n);
    
    return 0;
}