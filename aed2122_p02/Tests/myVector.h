#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
T MyVector<T>::max() const {
    if(values.empty()!=true){
        T vmax;
        for(int i=1; values.size()>i;i++){
            if(values[i]>vmax){
                vmax=values[i];
            }
        }
        return vmax;
    }else{
        EmptyVector e = EmptyVector();
        throw (e);
    }
}

// TODO
template<class T>
bool MyVector<T>::hasDuplicates() const {
    bool va=false;
    for(int i=0; values.size()>i; i++){
        for(int j=i+1; values.size()>j; j++){
            if(values[i]==values[j]){
                va=true;
            }
        }
    }
	return va;
}

// TODO
template<class T>
bool notIn(vector<T> vector, T number){
    for(int i=0; vector.size()>i; i++){
        if(number==vector[i])
            return false;
    }
    return true;
}

template<class T>
void MyVector<T>::removeDuplicates() {
    if(hasDuplicates()) {
        vector<T> t={};
        for(auto number: values){
            if(notIn(t,number))
                t.push_back(number);
        }
        values=t;
    }
}


