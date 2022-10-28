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
    Node *next;
};

template<class T>
struct Queue{
    Node<T>* first;
    Node<T>* last;
    Queue(){
        first = nullptr;
        last = nullptr;
    }
    void push(T val){
        Node<T>* elem = new Node<T>;
        if (last != nullptr){
            last->next = elem;
        } else {
            first = elem;
        }
        elem->value  = val;
        elem->next = nullptr;
        last = elem;
    }

    void pop(){
        Node<T>* to_del = first;
        first = first->next;
        if (first == nullptr)
        {
            last = nullptr;
        }
        delete to_del;
    }

    T front(){
        T ans = first->value;
        return ans;
    }
};

int main() {
    int q;
    cin>>q;
    Queue<int> queue;
    for (int i = 0; i < q; ++i) {
        char command;
        cin>>command;
        if(command == '+'){
            int val = 0;
            cin>>val;
            queue.push(val);
        } else if(command == '-'){
            cout<<queue.front()<<'\n';
            queue.pop();
        }
    }

    return 0;
}
