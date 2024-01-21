/*
Author : Bimochan Bhattarai
If you get any problem to understand the code or find any mistakes, please feel free to contact me.
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 49

class sta // Creating class for stack operation
{
private:
    int arr[50];
    int top = -1;

public:
    bool isempty() // defining isempty function in stack
    {
        // This function returns true if stack is empty else it returns false
        if (top == -1)
            return true;
        return false;
    }
    bool isfull() // defining isfull function in stack
    {
        // This function returns true if stack is full else it returns false
        if (top == MAX_SIZE - 1)
            return true;
        return false;
    }
    void push(int data) // defining push function in stack
    {
        // This function increase the pointing index of array by 1 and insert provided data in array
        if (!isfull())
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "You are out of storage !" << endl;
        }
    }
    int pop() // defining pop function in stack
    {
        // This function return data pointed by pointing index of array and decrease index of array by 1
        if (!isempty())
        {
            top--;
            return arr[top + 1];
        }
        else
        {
            cout << "The stack is empty!" << endl;
            return -1;
        }
    }
    int peak() // defining peak function in stack
    {
        // This function return data pointed by pointing index of array
        if (!isempty())
        {
            return arr[top];
        }
        else
        {
            cout << "The stack is empty!" << endl;
            return -1;
        }
    }
};

class UniversalQueue // defining the parent Queue class
{
protected:
    int arr[50];
    int front = 0, rear = 0;

public:
    void display()
    {
        // This function is used to display the content of queue if front > rear
        cout << "(";
        for (int i = front; i < rear - 1; i++)
        {
            cout << arr[i] << " ,";
        }
        cout << arr[rear - 1] << ")" << endl;
    }
};

class LinQueue : public UniversalQueue // Defining linear Queue inheriting from Queue parent
{
public:
    bool isfull()
    {
        // This function returns true if stack is full else it returns false
        if (rear == MAX_SIZE)
            return true;
        return false;
    }
    bool isempty()
    {
        // This function returns true if stack is empty else it returns false

        if (abs(rear - front) == 0)
            return true;
        return false;
    }
    void enqueue(int data)
    {
        // This function adds the data on the rear of the queue and increase the pointer by 1 if the queue isn't full
        if (!isfull())
        {
            arr[rear] = data;
            rear++;
        }
        else
        {
            cout << "Queue is full!" << endl;
        }
    }
    int dequeue()
    {
        // This function returns the front data at the array of the queue and increase the pointer by 1 if the queue isn't empty

        if (!isempty())
        {
            front++;
            return arr[front - 1];
        }
        else
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }
};

class CirQueue : public UniversalQueue
{
public:
    bool isfull()
    {
        // This function returns true if stack is full else it returns false
        if (front > rear)
            return true;
        return false;
    }
    bool isempty()
    {
        // This function returns true if stack is empty else it returns false
        if (abs(rear - front) == 0)
            return true;
        return false;
    }
    void enqueue(int data)
    {
        // This function adds the data on the rear of the queue and increase the pointer by 1 if the queue isn't full
        if (!isfull())
        {
            arr[rear] = data;
            rear = (rear + 1) % (MAX_SIZE + 1);
        }
        else
        {
            cout << "Queue is full!" << endl;
        }
    }
    int dequeue()
    {
        // This function returns the front data at the array of the queue and increase the pointer by 1 if the queue isn't empty
        if (!isempty())
        {
            int data = arr[front];
            front = (front + 1) % (MAX_SIZE + 1);
            return data;
        }
        else
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }
};

int main()
{
    // For stack
    sta S;
    S.push(100);
    cout << "Output from stack." << endl;
    cout << S.peak() << "   ";
    cout << S.pop() << endl
         << endl;

    // For LinearQueue
    LinQueue L;
    L.enqueue(13);
    L.enqueue(15);
    L.enqueue(24);
    L.enqueue(8);
    cout << "Output from Linear Queue." << endl;
    L.display();
    cout << L.dequeue() << endl;
    cout << L.dequeue() << endl;
    cout << L.dequeue() << endl
         << endl;

    // For Circular Queue
    CirQueue Q;
    Q.enqueue(5);
    Q.enqueue(7);
    Q.enqueue(55);
    Q.enqueue(4);
    cout << "Output from Circular Queue." << endl;
    Q.display();
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    return 0;
}