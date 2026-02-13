#include <optional>
#include <iostream>
using namespace std;

template<typename T, int len = 5>
class Stack {
	T arr[len];
	int s_size = 0;

	public:
	void push(T val) {
		if(s_size < len)
			arr[s_size++] = val;
		else
			cout << "stack overflow\n";
	}

	void pop() {
		if(s_size > 0)
			--s_size;
		else
			cout << "stack underflow\n";
	}

	std::optional<T> pop_top() {
		if(s_size > 0)
			return arr[--s_size];
		return std::nullopt;
	}

	std::optional<T> top() {
		if(s_size > 0)
			return arr[s_size - 1];
		return std::nullopt;
	}

	std::optional<T> peek(int index) {
		if(index >= 0 && index < s_size)
			return arr[index];
		return std::nullopt;
	}

	int size() {
		return s_size;
	}
	bool empty() { 
		return s_size == 0;
	}
	void clear() {
		s_size = 0;
	}


};

#include <iostream>
#include <optional>
using namespace std;

int main() {
    Stack<int, 5> s;  

    
    s.push(10);
    s.push(20);
    s.push(30);
    cout << " 10, 20, 30is pushed\n";
cout<<"elements of s\n";

for(int i=0;i<s.size();i++)
{
cout<<s.peek(i)<<" ";

}
cout<<endl;    
    auto t = s.top();
    if (t.has_value()) {
        cout << "top element: " << t.value() << "\n";
    } else {
        cout << "stack is empty\n";
    }

    
    auto p = s.peek(1);
    if (p.has_value()) {
        cout << "element at index 1: " << p.value() << "\n";
    } else {
        cout << "invalid index\n";
    }

   
    
    //  size
    cout << "current stack size: " << s.size() << "\n";

   
    cout << "stack empty " << boolalpha<<s.empty()  << "\n";

    
    s.clear();
    cout << "Stack cleared\n";

    
    cout << " stack empty  " << s.empty() << "\n";

   
   // t = s.top();
    if (auto t=s.top()) {
        cout << "Top element: " << t.value() << "\n";
        s.pop();
    } else {
        cout << "Stack underflow\n";
    }

   
    for (int i = 1; i <= 6; ++i) {
        s.push(i);
    }

    cout << "Final stack contents:\n";
    for (int i = 0; i < s.size(); ++i) {
        auto val = s.peek(i);
        if (val.has_value()) {
            cout << val.value() << " ";
        }
    }
    cout << "\n";

    return 0;
}

