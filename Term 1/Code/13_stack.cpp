//
// Created by alever.
//
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
struct Node {
    T value;
    Node *prev = nullptr;
};

template<class T>
struct Stack{
    Node<T>* top;
    Stack(){
        top = nullptr;
    }
    void push(T val){
        Node<T>* elem = new Node<T>;
        elem->value = val;
        if (top != nullptr){
            elem->prev = top;
            top = elem;
        } else {
            top = elem;
        }
    }

    void pop(){
        Node<T>* to_del = top;
        top = top->prev;
        delete to_del;
    }

    T back(){
        T ans = top->value;
        return ans;
    }

    bool empty(){
        return (top == nullptr);
    }
};

int main() {
    Stack<int> stack;
    int q;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        char ch;
        cin>>ch;
        if (ch == '+'){
            int val;
            cin>>val;
            stack.push(val);
        } else if (ch == '-') {
            cout<<stack.back()<<"\n";
            stack.pop();
        }
    }
    return 0;
}
