#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}

// ---------------------------------------------

// TODO
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    unsigned res=0;
    for (auto i = objs.begin(); i != objs.end(); i++) {
        if(i->getWeight()<=boxCapacity){
            res++;
            objects.push(*i);
            i++;
            objs.erase(prev(i, 1));
            i-=2;
        }
    }
	return res;
}


// TODO
Box PackagingMachine::searchBox(Object& obj) {
    HeapBox copy;
    bool e=false;
    Box res;
    while(!boxes.empty()){
        if(boxes.top().getFree()>=obj.getWeight() && !e){
            e= true;
            res=boxes.top();
        }else{
            copy.push(boxes.top());
        }
        boxes.pop();
    }
    boxes=copy;
    if(e)
        return res;
    return Box();
}


// TODO
unsigned PackagingMachine::packObjects() {
	return 0;
}

// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
	return res;
}



