#include <bits/stdc++.h>
using namespace std;

int main() {
    int operaciones;    
    while (cin >> operaciones) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool s1 = 1;
        bool q1 = 1;
        bool pq1 = 1;
        for (int i = 0 ; i < operaciones; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 1) {
                s.push(y);
                q.push(y);
                pq.push(y);
            } else if ((x == 2) && ((s.size()!=0) && (q.size()!=0) && (pq.size()!=0))) {
                 if (pq.top() != y) {
                    pq1 = 0;
                } if (q.front() != y) {
                    q1 = 0;
                } if (s.top() != y) {
                    s1 = 0;
                }
                pq.pop();
                q.pop();
                s.pop();
            } else {
                s1 = 0;
                q1 = 0;
                pq1 = 0;
            }
        }
        if (s1+q1+pq1>=2) {
            cout<<"not sure"<<endl;
        } 
        else if (s1) {
            cout<<"stack"<<endl;
        } 
        else if (q1) {
            cout<<"queue"<<endl;
        } 
        else if (pq1) {
            cout<<"priority queue"<<endl;
        } 
        else {
            cout<<"impossible"<<endl;
        }
    } 
    return 0;
}