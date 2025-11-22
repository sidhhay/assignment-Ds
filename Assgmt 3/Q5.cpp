#include<iostream>
#include<string>
using namespace std;
class stack{
    public:
    int top;
    int arr[100];
    public:
    stack(){
        top=-1;
    }
void push(int val){
    if(top>=99){
        cout<<"stack is full";
        return;
    }
    top++;
    arr[top]=val;

}
int pop(){
if(isempty()){
    cout<<"empty";
    return 0;
}

return arr[top--];
}
    int peek() {
        if (isempty()) return '\0';
        return arr[top];
    }
bool isempty(){
    return top<0;
}
};
int evaluate(char str[]){
    stack s;
    int i=0;
    while(str[i]!='\0'){
        char ch=str[i];
        if(ch>='0'&& ch<='9'){
            s.push(ch-'0');
        }
        else{
            int val1=s.pop();
            int val2=s.pop();
            switch(ch){
                case '+': s.push(val2+val1);break;
                 case '-': s.push(val2-val1);break;
                  case '*': s.push(val2*val1);break;
                   case '/': s.push(val2/val1);break;
                    case '^': s.push(val2^val1);break;
            }
        }
        i++;
    }
    return s.pop();
}

int main(){
    
 char str[100];
    cout << "Enter postfix expression: ";
    cin >> str;
    cout<<"result = "<<evaluate(str)<<endl;
    return 0;
}