int main() {

class MyStack {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int val) : data(val), next(nullptr) {}
        };
        Node* top;
    
    public:
        MyStack() { top = nullptr; }
    
        // Push operation: Insert element at the top
        void push(int x) {
            Node* newNode = new Node(x);
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (!top) return -1; // Stack is empty
            int poppedValue = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return poppedValue;
        }
    };
    return 0;
}