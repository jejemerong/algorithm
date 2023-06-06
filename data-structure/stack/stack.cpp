#include <iostream>
using namespace std;

#define MAX 1000 // Maximum size of Stack 정의

class Stack {
    int top;

    public:
        int a[MAX];
        Stack() {top = -1;} // initialization
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x){
    if(top >= (MAX - 1)) {
        cout << "Stack overflow";
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout << "Stack underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top < 0){
        cout << "빈 스택입니다이";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty () {
    return (top < 0);
}

int main () {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop();

    // 스택 출력
    while (!s.isEmpty()){
        cout << " " << s.peek();
        s.pop();
    }
    return 0;
}
