// Program to modify string based on '+' symbol

#include <cstdio>
#include <stack>
using namespace std;

int main() {
    char input[100];
    char result[100];
    stack<char> s;

    printf("Enter the string: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+') {
            if (!s.empty()) {
                s.pop();
            }
        } else {
            s.push(input[i]);
        }
    }

    int stack_size = s.size();
    for (int i = stack_size - 1; i >= 0; i--) {
        result[i] = s.top();
        s.pop();
    }
    result[stack_size] = '\0';

    printf("Output: %s\n", result);
    return 0;
}

