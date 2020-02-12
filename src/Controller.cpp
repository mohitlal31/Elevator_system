#include <iostream>

#include "../include/Controller.h"
#include "../include/Elevator.h"

void Controller::requestElevator(int currentFloor, m_button direction)
{
    std::cout << "Received request from floor: " << currentFloor << ", direction: "
              << static_cast<std::underlying_type<m_button>::type>(direction) << std::endl;

    //Todo: For now, we just forward the request to the elevator. Once more elevators are added,
    //the controller will delegate the request to the optimum elevator.

    m_elevator.requestFloor(currentFloor);
}