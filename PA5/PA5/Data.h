#include "Resources.h"

class Data {

public: // Member functions
	Data();
	const Data(int customer, int service, int elapsedTime);
	const Data(int customer, int service);
	~Data();

	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

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