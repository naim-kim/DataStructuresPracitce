#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void Push(const T& element) {
        elements.push_back(element);
    }

    void Pop() {
        if (!IsEmpty()) {
            elements.pop_back();
        } else {
            std::cerr << "Error: Stack is empty. Cannot pop.\n";
        }
    }

    const T& Top() const {
        if (!IsEmpty()) {
            return elements.back();
        } else {
            std::cerr << "Error: Stack is empty. Cannot get top element.\n";
            // Returning a default value if stack is empty.
            static T default_value;
            return default_value;
        }
    }

    bool IsEmpty() const {
        return elements.empty();
    }

    void Print() const {
        std::cout << "Stack elements: ";
        for (const auto& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Print(); // Should print: Stack elements: 1 2 3 4

    stack.Pop();
    stack.Print(); // Should print: Stack elements: 1 2 3

    std::cout << "Top element: " << stack.Top() << std::endl; // Should print: Top element: 3

    return 0;
}
