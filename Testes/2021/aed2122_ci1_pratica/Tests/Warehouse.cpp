#include "Warehouse.h"

Warehouse::Warehouse() {}

list<Packer> Warehouse::getPackers() {
    return packers;
}

void Warehouse::addPacker(const Packer &p) {
    packers.push_back(p);
}

list<stack<Order *>> Warehouse::getOrders() const {
    return processedOrders;
}

void Warehouse::setOrders(list<stack<Order *> > so) {
    processedOrders = so;
}


//=============================================================================
//TODO:
void Warehouse::sortPackers() {
    packers.sort();
}

//TODO:
unsigned Warehouse::removePackers(unsigned nOrders) {
    unsigned result = 0;
    for (auto it = packers.begin(); it != packers.end(); it++) {
        if (it->getOrderQueue().size() < nOrders) {
            result += it->getOrderQueue().size();
            it++;
            packers.erase(prev(it, 1));
            it--;
        }
    }

    return result;
}

//TODO:
void Warehouse::addPacker(unsigned idPacker, string namePacker) {
    Packer f = Packer(idPacker, namePacker);
    for (auto it = packers.begin(); it != packers.end(); it++) {
        if (it->getOrderQueue().size() >= 2) {
            f.addOrder(it->getOrderQueue().front());
            it->removeOrder();
        }
    }
    packers.push_back(f);
}

//TODO:
bool Warehouse::addToShorterQueue(Order *o) {
    if (packers.empty())
        return false;
    auto itMin = packers.begin();
    for (auto it = packers.begin(); it != packers.end(); it++) {
        if (it->getOrderQueue().size() < itMin->getOrderQueue().size()) {
            itMin = it;
        }
    }
    itMin->addOrder(o);
    return true;
}

//TODO:
unsigned Warehouse::processOrderByDeliveryType(string deliveryType, unsigned n) {
    unsigned res = 0;
    for (auto it = processedOrders.begin(); it != processedOrders.end(); it++) {
        if (deliveryType == it->top()->getDeliveryType()) {
            while(!it->empty() && res<n){
                it->pop();
                res++;
            }
        }
        if (it->empty()) {
            it++;
            processedOrders.erase(prev(it,1));
            it--;
        }
    }

    return res;
}
