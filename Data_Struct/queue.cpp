#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int main() 
{
    stack<int> s;
    s.push(2334);
    s.push(324);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();

    priority_queue<int> q;
    q.push(21);
    q.push(53);
    q.push(43);
    
    std::cout << q.top() << std::endl;
    q.pop();
    std::cout << q.top() << std::endl;
    q.pop();
    std::cout << q.top() << std::endl;
}
