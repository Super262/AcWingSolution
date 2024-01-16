//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0828_H
#define ACWINGSOLUTION_PROBLEM0828_H

#include <iostream>

using namespace std;

class Problem0828
{
private:
    void pop(unsigned long &top)
    {
        --top;
    }

    void push(const int &value, int *data, unsigned long &top)
    {
        data[++top] = value;
    }

    bool empty(const unsigned long &top)
    {
        return top == 0;
    }

    int peek(const int *data, const unsigned long &top)
    {
        return data[top];
    }

    int main()
    {
        unsigned long m;
        cin >> m;
        int data[m];
        unsigned long top = 0;
        for (int i = 0, value; i < m; ++i)
        {
            string op;
            cin >> op;
            if (op == "push")
            {
                cin >> value;
                push(value, data, top);
            }
            else if (op == "query")
            {
                cout << peek(data, top) << endl;
            }
            else if (op == "empty")
            {
                cout << (empty(top) ? "YES" : "NO") << endl;
            }
            else
            {
                pop(top);
            }
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0828_H
