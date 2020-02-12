#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <locale>
#include <random>
#include <string>
#include <vector>

#include "../include/Controller.h"
#include "../include/Elevator.h"

//ToDo: 1- Create a single elevator object on a separate thread. Add time delays to simulate actual elevator
//functionality.

//ToDo: 2- Create multiple elevators, each on a separate thread. The controller will be responsible
//for delegating the request to the closest elevator.

//ToDo: 3- Add a GUI with buttons on each floor and inside each elevator. This will simulate the actual system
//with internal and external requests

void printGeneratedRequests(const std::vector<int> &requests, const std::vector<int> &requestDirections)
{
    std::cout << "Floor" << std::setw(10) << "Direction" << std::endl;
    for (size_t i = 0; i < requests.size(); ++i)
    {
        if (requestDirections[i] == 0)
            std::cout << requests[i] << std::setw(10) << "UP" << std::endl;
        else
            std::cout << requests[i] << std::setw(10) << "DOWN" << std::endl;
    }
}

void generateExternalRequests(int requestsCount, int floors)
{
    //generate a vector of random floors
    std::vector<int> requests(requestsCount);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> floorDistribution(0, floors);
    for (int i = 0; i < requestsCount; ++i)
    {
        std::generate(requests.begin(), requests.end(), [&]() { return floorDistribution(generator); });
    }

    //generate a vector of random directions(up/down) button clicks in the
    //above generated floors
    std::vector<int> requestDirections(requestsCount);
    std::uniform_int_distribution<int> directionDistribution(0, 1);
    for (int i = 0; i < requestsCount; ++i)
    {
        std::generate(requestDirections.begin(), requestDirections.end(), [&]() { return directionDistribution(generator); });
    }

    printGeneratedRequests(requests, requestDirections);
}

int main()
{
    //All external requests are sent to the controller. Once inside an elevator,
    //the internal requests are sent directly to that elevator.
    while (1)
    {
        std::cout << "Do you wish to exit the program? (y/n)" << std::endl;
        char isExit;
        std::cin >> isExit;
        if (std::tolower(isExit) == 'y')
            break;

        std::cout << "Enter the number of floors in the building" << std::endl;
        int floors;
        std::cin >> floors;

        std::cout << "Enter the number of external requests you would like to simulate" << std::endl;
        int requestsCount;
        std::cin >> requestsCount;

        std::cout << "Randomly generating " << requestsCount << " external requests..." << std::endl
                  << std::endl;
        generateExternalRequests(requestsCount, floors);

        std::deque<int> requests;
        int currentPosition = 0;
        Elevator::direction currentDirection = Elevator::direction::UP;
        
        Elevator elevator_1();
        Controller controller(elevator_1, floors);
    }
}
