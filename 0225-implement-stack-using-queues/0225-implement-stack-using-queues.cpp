#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1; // Declared as a class member so all methods can access it

public:
    MyStack() {
        // Constructor can remain empty
    }
    
    void push(int x) {
        int s = q1.size();
        q1.push(x);
        
        // Move all previous elements behind the newly pushed element
        for (int i = 0; i < s; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int x = q1.front(); // The newest element is always at the front
        q1.pop();           // Removes the front element
        return x;
    }
    
    int top() {
        return q1.front();  // Only return the front element without removing it
    }
    
    bool empty() {
        return q1.empty();
    }
};
