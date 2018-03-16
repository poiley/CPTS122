/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 5
* Date : Mar 1st, 2018
* Credits : Andrew O'Fallon for instructions and guidance with Queue
*			code
**********************************************************************/

#include "Resources.h"

class Data {

public: // Member functions
	Data();
	Data(const Data &copy);
	Data(int customer, int service, int elapsedTime);
	Data(int customer, int service);
	~Data();

	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;

	void setCustomerNumber(int n);
	void setServiceTime(int n);
	void setTotalTime(int n);
private:
	int customerNumber; // Unique identifier
						// Starts at 1
						// After 24 hours should be reset to 1
	int serviceTime;	// Random time 
						// Varies between express and normal lanes
						// Units in minutes
	int totalTime;      // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer
						// Units in minutes

};