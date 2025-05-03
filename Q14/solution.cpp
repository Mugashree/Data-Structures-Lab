//Program to check valid parenthesis input

#include <stack>
#include <string>
#include <cstdio>

using namespace std;

class Solution
{
public:
    stack<char> stc;

    bool isValid(const string& s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stc.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!stc.empty() && stc.top() == '(')
                {
                    stc.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stc.empty();
    }
};

int main()
{
    Solution sol;
    int choice;
    char input[100]; 

    while (1)
    {
        printf("Menu:\n");
        printf("1. Check balance\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the string to check balance: ");
            scanf("%s", input);  
            
            if (sol.isValid(input))
            {
                printf("The parentheses are balanced.\n");
            }
            else
            {
                printf("The parentheses are not balanced.\n");
            }
            break;

        case 2:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}

