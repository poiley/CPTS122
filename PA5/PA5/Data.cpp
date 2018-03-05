#include "Data.h"

Data::Data() {
	customerNumber = -1;
	serviceTime    = -1;
	totalTime      = -1;
}

Data::Data(int customer, int service, int elapsedTime) {
	customerNumber = customer;
	serviceTime	   = service;
	totalTime	   = serviceTime + elapsedTime;
}

Data::Data(int customer, int service) {
	customerNumber = customer;
	serviceTime	   = service;
	totalTime      = 0;
}

Data::~Data() {}

int Data::getCustomerNumber() { return customerNumber; }
int Data::getServiceTime() { return serviceTime; }
int Data::getTotalTime() { return totalTime; }

void Data::setCustomerNumber(int n) { customerNumber = n; }
void Data::setServiceTime(int n) { serviceTime = n; }
void Data::setTotalTime(int n) { totalTime = n; }
