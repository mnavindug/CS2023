#include <iostream>
#include <chrono>
#define MAX 10

using namespace std;
using namespace std::chrono;

//implementation of stack using an array
class ArrayStack {
private:
    int top;
    int array[MAX];  //creating a static array of size MAX
public:
    ArrayStack() {
        top = -1;   //initializing the top index 
    }

    void push(int value) {  //push method
        if (top >= MAX-1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            array[top] = value;
        }
    }

    int pop() {  //pop method
        int value;
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
            
        }
        else {
            value = array[top];
            top--;
            return value;
            
        }
    }
    
    void isEmpty(){
        if (top==-1){
            cout<<" Stack is empty."<<"\n";
        }
        else{
             cout<<" Stack is not empty."<<"\n";
        }
    }
    
    void isFull(){
        if (top==MAX-1){
            cout<<"Stack is full."<<"\n";
        }
        else {
            cout<<"Stack is not full."<<"\n";
        }
    }
    
    void StackTop(){
        if (top!=-1){
            cout<<array[top]<<"\n";
        }
        else {
            cout<<" There are no elements in stack."<<"\n";
        }
    }
    
    void Display(){
        for (int i=top;i>=0; i--){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};

//implementation of a stack using a linked list

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedlistStack {
private:
    StackNode* top;
    int size;
public:
    LinkedlistStack() {
        top = NULL;
        size = 0;
    }

    void push(int value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            int value = top->data;
            StackNode* temp = top;
            top = top->next;
            delete temp;
            size--;
            return value;
        }
    }

    bool isEmpty() {
        return top == NULL; 
        
        }

    bool isFull() {
        return false; // Linked lists don't have a maximum size limit
    }

    int StackTop() {
        if (top == NULL) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else {
            return top->data;
        }
    }

    void Display() {
        if (top == NULL) {
            cout << "Stack is Empty" << endl;
        }
        else {
            StackNode* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};

int main() {
    ArrayStack s1;
    auto start = high_resolution_clock::now();
    s1.push(8);
    s1.push(10);
    s1.push(5);
    s1.push(11);
    s1.push(15);
    s1.push(23);
    s1.push(6);
    s1.push(18);
    s1.push(20);
    s1.push(17);
    s1.Display();
    s1.StackTop();
    cout << s1.pop() << endl; 
    cout << s1.pop() << endl; 
    cout << s1.pop() << endl; 
    cout << s1.pop() << endl; 
    cout << s1.pop() << endl; 
    s1.Display();
    s1.push(4);
    s1.push(30);
    s1.push(3);
    s1.Display();
    s1.isEmpty();
    s1.isFull();
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by array stack: " << duration.count() << " microseconds" << endl;
    
    cout<<"---------------------------------"<<"\n";
    
    LinkedlistStack s2;
    start = high_resolution_clock::now();
    s2.push(8);
    s2.push(10);
    s2.push(5);
    s2.push(11);
    s2.push(15);
    s2.push(23);
    s2.push(6);
    s2.push(18);
    s2.push(20);
    s2.push(17);
    s2.Display();
    cout << s2.StackTop() << endl; 
    cout << s2.pop() << endl; 
    cout << s2.pop() << endl; 
    cout << s2.pop() << endl; 
    cout << s2.pop() << endl; 
    cout << s2.pop() << endl; 
    s2.Display();
    s2.push(4);
    s2.push(30);
    s2.push(3);
    s2.Display();
    cout << s2.isEmpty() << endl; 
    cout << s2.isFull() << endl; 
    stop = high_resolution_clock::now();
    
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by linked list stack: " << duration.count() << " microseconds" << endl;
    
    return 0;
}
