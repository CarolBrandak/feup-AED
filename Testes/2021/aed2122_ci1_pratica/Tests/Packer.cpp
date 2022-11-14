#include "Packer.h"

Packer::Packer(unsigned idPacker, string namePacker) : idPacker(idPacker), namePacker(namePacker) {}

unsigned Packer::getIdPacker() const {
    return idPacker;
}

string Packer::getNamePacker() const {
    return namePacker;
}

void Packer::addOrder(Order *o) {
    myOrderQueue.push(o);
}

void Packer::removeOrder() {
    myOrderQueue.pop();
}

queue<Order *> Packer::getOrderQueue() const {
    return myOrderQueue;
}

bool Packer::operator <(const Packer &p) const{
    if (myOrderQueue.size() == p.getOrderQueue().size()){
        if (namePacker == p.getNamePacker()){
            return idPacker < p.getIdPacker();
        }
        return namePacker < p.getNamePacker();
    }
    return myOrderQueue.size() > p.getOrderQueue().size();
}


