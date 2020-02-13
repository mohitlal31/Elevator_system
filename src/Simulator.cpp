#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <locale>
#include <random>
#include <unordered_set>
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

void printGeneratedRequests(const std::unordered_set<int> &requests)
{
    std::cout << "************************************" << std::endl;
    std::cout << "Floor" << std::endl
              << std::endl;
    for (auto &request : requests)
    {
        std::cout << request << std::endl;
    }
    std::cout << "************************************" << std::endl;
}

void generateExternalRequests(int requestsCount, int floors, std::unordered_set<int> &requests)
{
    //generate a set of random floors
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> floorDistribution(0, floors);
    for (int i = 0; i < requestsCount;)
    {
        int random = floorDistribution(generator);
        if (requests.find(random) == requests.end())
        {
            requests.insert(random);
            ++i;
        }
    }
    printGeneratedRequests(requests);
}

int main()
{
    while (1)
    {
        std::cout << "Enter the number of floors in the building" << std::endl;
        int floors;
        std::cin >> floors;
        std::cout << std::endl;

        std::cout << "Enter the number of queued requests you would like to simulate" << std::endl;
        int requestsCount;
        std::cin >> requestsCount;
        std::cout << std::endl;

        std::cout << "Following " << requestsCount << " requests are already queued in the system..." << std::endl
                  << std::endl;
        std::unordered_set<int> requestSet;
        generateExternalRequests(requestsCount, floors, requestSet);

        std::deque<int> requests(requestSet.begin(), requestSet.end());
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> floorDistribution(0, floors);
        int currentPosition = floorDistribution(generator);
        Elevator::direction currentDirection = Elevator::direction::UP;
        std::cout << std::endl;
        if (currentPosition == floors)
        {
            currentDirection = Elevator::direction::DOWN;
            std::cout << "Elevator is currently at floor " << currentPosition << " going down" << std::endl;
        }
        else if (currentPosition == 0)
        {
            currentDirection = Elevator::direction::UP;
            std::cout << "Elevator is currently at floor " << currentPosition << " going up" << std::endl;
        }
        else
        {
            std::default_random_engine generator;
            std::uniform_int_distribution<int> floorDistribution(0, 1);
            int random = floorDistribution(generator);
            if (random == 0)
            {
                currentDirection = Elevator::direction::UP;
                std::cout << "Elevator is currently at floor " << currentPosition << " going up" << std::endl;
            }
            else
            {
                currentDirection = Elevator::direction::DOWN;
                std::cout << "Elevator is currently at floor " << currentPosition << " going down" << std::endl;
            }
        }
        std::cout << std::endl;

        Elevator elevator_1(requests, currentPosition, currentDirection);
        Controller controller(elevator_1, floors);

        std::cout << "Enter your current floor and the direction you wish to go(up/down)" << std::endl;
        int floor;
        std::string direction;
        std::cin >> floor >> direction;
        std::cout << std::endl;
        std::cout << "Starting elevator simulation......" << std::endl << std::endl;
        if (floor >= 0 && floor <= floors)
        {
            if (direction == "down")
                controller.requestElevator(floor, Controller::m_button::DOWN);
            else if (direction == "up")
                controller.requestElevator(floor, Controller::m_button::UP);
            else
            {
                std::cout << "You entered an incorrect string. Going down by default" << std::endl;
                controller.requestElevator(floor, Controller::m_button::DOWN);
            }
        }
        else
        {
            std::cout << "You entered a non-existent floor" << std::endl;
            break;
        }

        std::cout << "Do you wish to exit the program? (y/n)" << std::endl;
        char isExit;
        std::cin >> isExit;
        if (std::tolower(isExit) == 'y')
            break;
    }
}
