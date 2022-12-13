#include "UverEats.h"

UverEats::UverEats() {}

void UverEats::addClient(Client client){
    clients.push_back(client);
}

void UverEats::addRestaurant(Restaurant restaurant) {
    restaurants.push_back(restaurant);
}

vector<Client> UverEats::getClients() const {
    return clients;
}

const list<Restaurant> &UverEats::getRestaurants() const {
    return restaurants;
}

void UverEats::addDriver(Driver driver) {
    drivers.insert(driver);
}

const set<Driver> &UverEats::getDrivers() const {
    return drivers;
}

//=============================================================================

//TODO
void UverEats::sortClients()
{
    sort(clients.begin(), clients.end());
}

//TODO
float UverEats::averageRestaurantRating(int numMinOrders) const
{
    float numRes=0.0;
    float res=0.0;
    for(const auto & restaurant : restaurants){
        if( restaurant.getOrders().size() > numMinOrders){
            res+=restaurant.getRating();
            numRes++;
        }
    }
    if (numRes == 0) return 0.0;
    res/=numRes;
    return res;
}

//TODO
void UverEats::removeRestaurants(float minRating)
{
    for (auto restaurant = restaurants.begin(); restaurant!=restaurants.end(); restaurant++) {
        if(restaurant->getRating()<minRating){
            restaurant++;
            restaurants.erase(prev(restaurant, 1));
            restaurant--;
        }
    }
}

//TODO
vector<Driver> UverEats::getDriversWithOrders(int numOrders) const {
    vector<Driver> result;
    for (auto it=drivers.begin();it!=drivers.end();it++) {
        if(it->getToDeliver().size()<numOrders){
            result.push_back(*it);
        }
    }
    sort(result.begin(), result.end());
    return result;
}


//TODO:
void UverEats::createRestaurantBranch(string restMain, string restBranch) {
    Restaurant res=Restaurant(restBranch);

    for( auto & restaurant : restaurants){
        if( restaurant.getName()==restMain){
            queue<Order *> copy;
            int i=1;
            while(!restaurant.getOrders().empty()){
                if(i%2==0){
                    res.insertOrder(restaurant.getOrders().front());
                    restaurant.removeFrontOrder();
                }else{
                    copy.push(restaurant.getOrders().front());
                    restaurant.removeFrontOrder();
                }
                i++;
            }

            while(!copy.empty()){
                restaurant.insertOrder(copy.front());
                copy.pop();
            }

        }
    }
    restaurants.push_back(res);
}