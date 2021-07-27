#include<iostream>
#include <stack>

bool isValid(std::string s)
{
    std::stack<char> paraStack;

    for (int i = 0; i < s.size(); ++i)
    {
        switch (s[i])
        {
            case '(':
            {
                paraStack.push(s[i]);
                break;
            }
            case ')':
            {
                if (!paraStack.empty())
                {
                    if (paraStack.top() == '(')
                    {
                        paraStack.pop();
                    }
                    else
                    {
                        paraStack.push(s[i]);
                    }
                }
                else
                {
                    return false;
                }

                break;
            }
            case '{':
            {
                paraStack.push(s[i]);
                break;
            }
            case '}':
            {
                if (!paraStack.empty())
                {
                    if (paraStack.top() == '{')
                    {
                        paraStack.pop();
                    }
                    else
                    {
                        paraStack.push(s[i]);
                    }
                }
                else
                {
                    return false;
                }

                break;
            }
            case '[':
            {
                paraStack.push(s[i]);
                break;
            }
            case ']':
            {
                if (!paraStack.empty())
                {
                    if (paraStack.top() == '[')
                    {
                        paraStack.pop();
                    }
                    else
                    {
                        paraStack.push(s[i]);
                    }
                }
                else
                {
                    return false;
                }

                break;
            }
            default:
            {
                std::cout << "Oops, something went wrong!\n";
                break;
            }
        }
    }

    if (paraStack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    // TEST CASES
    std::string test1 = "[]";       // Valid
    std::string test2 = "[]}";      // Invalid

    std::string test3 = "[()]{}{[()()]()}";     // Valid
    std::string test4 = "[()]{}[()()]()}";      // Invalid

    bool ans = isValid(test3);

    if (ans)
    {
        std::cout << "Parenthesis string is valid\n";
    }
    else
    {
        std::cout << "Parenthesis string is invalid\n";
    }

	return 0;
}