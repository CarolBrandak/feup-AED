#include "Restaurant.h"

void Restaurant::insertOrder(Order* order) {
    orders.push(order);
}

void Restaurant::removeFrontOrder() {
    orders.pop();
}

const string &Restaurant::getName() const {
    return name;
}

float Restaurant::getRating() const {
    return rating;
}

const queue<Order *> &Restaurant::getOrders() const {
    return orders;
}


//=============================================================================

//TODO
void Restaurant::removeOrder(string client, string orderNumber) {

    queue<Order *> copy;
    while(!orders.empty()){
        if(orders.front()->getClient()!=client && orders.front()->getOrderNumber()!=orderNumber){
            copy.push(orders.front());
        }
        orders.pop();
    }
    orders=copy;
}
