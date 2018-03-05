/*********************************************************************
* Programmer: Benjamin Poile
* Class : CptS 122, Spring 2018
* Programming Assignment : PA 5
* Date : Mar 1st, 2018
* Credits : Andrew O'Fallon for instructions
**********************************************************************/

#include "Resources.h"
#include "Queue.h"

int main(void) {
	srand(time(NULL));
	int minutesToRun = 0; // Number of minutes to run simulation, as put in by the user.
	
	// Get user input for the amount of simulated minutes the app should run.
	cout << "How long would like the simulation to run?\n-> ";
	cin >> minutesToRun;
	cout << "\nSimulation will run for " << minutesToRun << " simulated minutes." << endl;

	/*Queue `express` represents the express lane
	  Customers arrive every one to five minutes
	  Service times range from one to five minutes*/
	Queue *express;
	
	/*Queue `normal` represents the normale lane
	  Customers arrive every three to eight minutes
	  Service times range from three to eight minutes*/
	Queue *normal;
	
	// ARRIVAL TIME - GENERATE RANDOM NUMBER BETWEEN 1 - 5 / 3 - 8
	int expressArrivalTime = ( rand() % 5 ) + 1, normalArrivalTime = ( rand() % 5 ) + 4;

	// Assign starting customer ID
	int customerID = 1;

	// Total time elapsed = 0
	int timeElapsed = 0;

	// Create initial data for express and normal lines
	Data *expressData = new Data(1, (rand() % 5 ) + 1, 0);
	Data *normalData = new Data(1, (rand() % 5) + 4, 0);
	
	// Start sum of serviceTimes of customers in line
	int expressLineTime = 0, normalLineTime = 0;

	// Total time elapsed = 0. Begin simulation loop.	
	for (timeElapsed; timeElapsed < minutesToRun; timeElapsed++) {
		// At arrival time, generate service time for each customer.
		if (timeElapsed == expressArrivalTime || (timeElapsed == expressData->getTotalTime() && timeElapsed != 0)) {
			//express->enqueue(*expressData);
			cout << "Ex:\tCustomer " << expressData->getCustomerNumber() << " has queued. " << endl;
			cout << "\tCurrent Time: " << timeElapsed << endl;
			cout << "\tService Time: " << expressData->getServiceTime() << endl;
			cout << "\tElapsed Time: " << expressData->getTotalTime() << endl << endl;
		}

		if (timeElapsed == expressData->getTotalTime()) {
			//Data deq = express->dequeue();
			cout << "Customer " << expressData->getCustomerNumber() << " has checked out." << endl;
			expressData = new Data(expressData->getCustomerNumber() + 1, (rand() % 5) + 1, timeElapsed);
		}

		// Process Customer based on service time.

		// Randomly generate the arrival time of the next customer in each line.
		// Update elapsed time to add one minute
		// If a new customer comes, display the appropriate messages.

		// Every 10 minutes, print out entire queue for each lines
		if (timeElapsed % 10 == 0 && timeElapsed != 0) {
			cout << "\nEXPRESS QUEUE:" << endl;
			//express->printQueue();
			cout << "\nNORMAL QUEUE:" << endl;
			//normal->printQueue();
		}

	} // Repeat for `minutesToRun` minutes.
}