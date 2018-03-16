/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 5
* Date : Mar 1st, 2018
* Credits : Andrew O'Fallon for instructions and guidance with Queue 
*			code
**********************************************************************/
#include "Data.h"

/**CONSTRUCTORS**/
Data::Data() {
	customerNumber = -1;
	serviceTime    = -1;
	totalTime      = -1;
}

Data::Data(const Data &copy) {
	customerNumber = copy.getCustomerNumber();
	serviceTime = copy.getServiceTime();
	totalTime = copy.getTotalTime();
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

/**DECONSTRUCTOR**/
Data::~Data() {}

/**GETTERS**/
int Data::getCustomerNumber() const { return customerNumber; }
int Data::getServiceTime() const { return serviceTime; }
int Data::getTotalTime() const { return totalTime; }

/**SETTERS**/
void Data::setCustomerNumber(int n) { customerNumber = n; }
void Data::setServiceTime(int n) { serviceTime = n; }
void Data::setTotalTime(int n) { totalTime = n; }
