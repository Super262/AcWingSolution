//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0829_H
#define ACWINGSOLUTION_PROBLEM0829_H

#include <iostream>

using namespace std;

class Problem0829
{
private:
    void pop(unsigned long &front)
    {
        ++front;
    }

    void push(const int &value, int *data, unsigned long &end, const unsigned long &m)
    {
        data[end] = value;
        ++end;
        end %= m;
    }

    bool empty(const unsigned long &front, const unsigned long &end)
    {
        return front == end;
    }

    int peek(int *data, unsigned long &front, const unsigned long &m)
    {
        front %= m;
        return data[front];
    }

    int main()
    {
        unsigned long m;
        cin >> m;
        int data[m];
        unsigned long front = 0;
        unsigned long end = 0;
        string op;
        for (int i = 0, value; i < m; ++i)
        {
            cin >> op;
            if (op == "push")
            {
                cin >> value;
                push(value, data, end, m);
            }
            else if (op == "query")
            {
                cout << peek(data, front, m) << endl;
            }
            else if (op == "empty")
            {
                cout << (empty(front, end) ? "YES" : "NO") << endl;
            }
            else
            {
                pop(front);
            }
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0829_H
