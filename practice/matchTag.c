#include <stdio.h>
#include <string.h>
#include <stack>

struct tag_s
{
    char name[255];
    int open;
};

typedef tag_s tag;

char c; // current
// get next c
int next_c()
{
    int res = scanf("%c", &c);
    printf("%c", c);
    return res;
}
// get tag
tag get_tag()
{
    tag t;
    int process = 1;
    int flag = 0; // flag for /
    int i = 0;
    while (process)
    {
        if (next_c() == EOF)
        {
            t.open = -1;
            return t;
        }

        switch (c)
        {
        case '<':
            t.open = -1;
            return t;
        case '/':
            if (flag == 1)
            {
                t.open = -1;
                return t;
            }
            flag = 1;
            break;
        case '>':
            process = 0;
            break;
        default:
            if (c < '0' || (c > '9' && c < 'A') || c > 'z' || (c > 'Z' && c < 'a'))
            {
                t.open = -1;
                return t;
            }
            t.name[i] = c;
            i++;
            break;
        }
    }
    t.name[i] = '\0';
    t.open = !flag;
    return t;
}
// html valid
int html_valid()
{
    int process = 1;
    tag t;
    std::stack<tag> stack;
    while (process)
    {
        if (next_c() == EOF)
        {
            process = 0;
        }

        switch (c)
        {
        case '<':

            t = get_tag();
            if (t.open == -1)
            {
                return 0;
            }
            if (t.open == 1)
            {
                stack.push(t);
            }
            if (t.open == 0)
            {
                if (strcmp(stack.top().name, t.name) != 0)
                {
                    return 0;
                }

                if (stack.top().open != 1)
                {
                    return 0;
                }
                stack.pop();
            }

            break;
        case '>':
            return 0;
        default:
            break;
        }
    }

    if (stack.empty())
    {
        return 1;
    }

    return 0;
}

int main()
{
    int valid = html_valid();
    if (valid)
    {
        printf("HTML VALID ");
    }
    else
    {
        printf("HTML INVALID !!!!");
    }
}