# include <iostream>
# include <stack>
using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//TODO
template <class T>
bool StackExt<T>::empty() const {
    return values.empty();
}

//TODO
template <class T>
T& StackExt<T>::top() {
    if(!values.empty())
        return values.top();
}

//TODO
template <class T>
void StackExt<T>::pop() {
    if (this->minimums.top() == this->values.top()) {
        this->minimums.pop();
    }
    this->values.pop();
}
/*
values.push(val);

// Add it to the min. values stack, if needed
if (minimums.size() == 0){
minimums.push(val);			// First element! Add it, it is the minimum
}
else if (val <= minimums.top()){	// New minimum value
minimums.push(val);
}*/
//TODO
template <class T>
void StackExt<T>::push(const T& val) {
    if (minimums.empty())
        minimums.push(val);

    if (val <= minimums.top())
        minimums.push(val);
    values.push(val);
}

//TODO
template <class T>
T& StackExt<T>::findMin() {
    T& result = this->minimums.top();
    return result;
}