#include "Runway.hpp"
#include "Random.hpp"
using namespace std;

void initialized(int &end_time, int &queue_limit
	, double &arrival_rate, double &departure_rate);

int main() {
	int end_time;
	int queue_limit;
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialized(end_time, queue_limit, arrival_rate, departure_rate);
	srand(time(NULL));
	Random variable;

	Runway small_airport_1(queue_limit);
	Runway small_airport_2(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) {
		int number_arrivals = variable.poisson(arrival_rate);
		int number_departures = variable.poisson(departure_rate);

		for (int i = 0; i < number_arrivals; i++) {									//这里改成你要的那个形式了 
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport_1.can_land(current_plane) != true) {
				if (small_airport_2.can_land(current_plane) != true)
					current_plane.refuse();
			}
		}
		/*元的好小同学，下面的函数 一点都没有改，原因是
		你看activity函数永远都是将一个跑道中的landing队列先出玩再出takingoff队列
		所以说在前面landing队列满了之后添加到small_airport_2之后，takingoff队列还是可以正常添加

		然后我就沿用了之前的人性化的方法，如果small_airport_1的队列是空的话，那么确保两边是同时增长的


		我认为算法现在已经没有什么问题了
		*/
		for (int j = 0; j<number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport_1.landing_Size() == 0) {
				if (small_airport_2.takingoff_Size() > small_airport_1.landing_Size()) {
					if (small_airport_1.can_depart(current_plane) != true)
						current_plane.refuse();
				}
				else {
					if (small_airport_2.can_depart(current_plane) != true)
						current_plane.refuse();
				}
			}
			else {
				if (small_airport_2.can_depart(current_plane) != true)
					current_plane.refuse();
			}
		}
		cout << "Time: " << current_time << endl;

		Plane moving_plane;
		switch (small_airport_1.activity(current_time, moving_plane)) {
		case land:
			moving_plane.land(current_time, 1);
			break;
		case takeoff:
			moving_plane.fly(current_time, 1);
			break;
		case idle:
			small_airport_1.run_idle();
			break;
		}
		switch (small_airport_2.activity(current_time, moving_plane)) {
		case land:
			moving_plane.land(current_time, 2);
			break;
		case takeoff:
			moving_plane.fly(current_time, 2);
			break;
		case idle:
			small_airport_2.run_idle();
			break;
		}
	}
	Runway::shut_down(end_time);
	system("pause");
}

void initialized(int &end_time, int &queue_limit
	, double &arrival_rate, double &departure_rate)
{
	cout << "This program simulates an airport with two runways." << endl;
	cout << "One runway is for landing, the other is for taking off." << endl;
	cout << "If a runway is empty, it can have the other use." << endl;
	cout << "One plane can land or depart in each unit of time." << endl;
	cout << "Up to what number of planes can be waiting to land "
		<< "or take off at any time?" << endl;
	cin >> queue_limit;
	cout << "How many units of time will the simulation run?" << endl;
	cin >> end_time;
	bool acceptable;
	do {
		cout << "Expected number of arrivals per unit time?" << endl;
		cin >> arrival_rate;
		cout << "Expected number of departures_per unit time?" << endl;
		cin >> departure_rate;
		if (arrival_rate<0.0 || departure_rate<0.0)
			cerr << "These rates must be nonnegative." << endl;
		else
			acceptable = true;
		if (acceptable && arrival_rate + departure_rate > 2.0)
			cerr << "Safety Warning: This airport will become saturated." << endl;
	} while (!acceptable);
}

