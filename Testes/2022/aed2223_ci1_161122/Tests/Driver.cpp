#include "Driver.h"

Driver::Driver(unsigned int idDriver, const string &nameDriver) : driverId(idDriver), driverName(nameDriver) {}

unsigned int Driver::getIdDriver() const {
    return driverId;
}

const string &Driver::getNameDriver() const {
    return driverName;
}

const stack<Order> &Driver::getToDeliver() const {
    return toDeliver;
}

void Driver::insertOrder(Order order) {
    toDeliver.push(order);
}

//=============================================================================

// TODO
bool Driver::operator<(const Driver &d1) const {
    if(toDeliver.size()==d1.getToDeliver().size())
        return driverId<d1.getIdDriver();
    return toDeliver.size()>d1.getToDeliver().size();
}

// TODO
vector<string> Driver::checkCommonClients(const Driver &d2) {
    vector<string> result;
    stack<Order> copy = toDeliver;
    while(!copy.empty()){
        stack<Order> d2copy = d2.getToDeliver();
        while(!d2copy.empty()){
            if(copy.top().getClient()==d2copy.top().getClient()){
                result.push_back(copy.top().getClient());
                break;
            }
            d2copy.pop();
        }
        copy.pop();
    }
    return result;
}

