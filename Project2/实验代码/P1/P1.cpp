#include "Runway.hpp"
#include "Random.hpp"
using namespace std;

void initialized(int &end_time, int &queue_limit
	, double &arrival_rate, double &departure_rate);
void run_idle(int time);


int main() {
	int end_time;
	int queue_limit;
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialized(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;
	Runway small_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) {
		int number_arrivals = variable.poisson(arrival_rate);
		//current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport.can_land(current_plane) != true)
				current_plane.refuse();
		}
		int number_departures = variable.poisson(departure_rate);
		//current depart requests
		for (int j = 0; j<number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport.can_depart(current_plane) != true)
				current_plane.refuse();
		}
		Plane moving_plane;
		switch (small_airport.activity(current_time,moving_plane)) {
		case land:
			moving_plane.land(current_time);
			break;
		case takeoff:
			moving_plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
			break;
		}
	}
	small_airport.shut_down(end_time);
	system("pause");
}

void initialized(int &end_time, int &queue_limit
	, double &arrival_rate, double &departure_rate)
{
	cout << "This program simulates an airport with only one runway." << endl;
	cout << "One plane can land or depart in each unit of time." << endl;
	cout << "Up to what number of planes can be waiting to land "
		<< "or take off at any time?" << endl;
	cin >> queue_limit;
	cout << "How many units of time will the simulation run?" << endl;
	cin >> end_time;
	bool acceptable;
	do {
		cout << "Expected number of arrivals per unit time" << endl;
		cin >> arrival_rate;
		cout << "Expected number of departures_per unit time?" << endl;
		cin >> departure_rate;
		if (arrival_rate<0.0 || departure_rate<0.0)
			cerr << "These rates must be nonnegative." << endl;
		else
			acceptable = true;
		if (acceptable && arrival_rate + departure_rate > 1.0)
			cerr << "Safety Warning: This airport will become saturated." << endl;
	} while (!acceptable);
	cout << "-----------------------------------------------------------------------" << endl;
}

void run_idle(int time) {
	cout << "Time: " << time << endl;
	cout << "Runway is idle. " << endl;
}