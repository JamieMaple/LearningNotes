#include <iostream>
#include <stack>

int main() {
    const char s[] = "1237(12(34)56(78))";
    std::stack<char> st;

    for (auto c : s) {
        if (c != ')') {
            st.push(c);
        } else {
            while (!st.empty() && st.top() != '(') {
                std::cout << st.top() << " ";
                st.pop();
            }
            st.pop();
            st.push('*');
            std::cout << std::endl;
        }
    }

    while (!st.empty()) {
        std::cout << st.top();
        st.pop();
    }
    std::cout << std::endl;

    return 0;
}
