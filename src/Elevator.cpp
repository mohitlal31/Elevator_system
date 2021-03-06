#include "../include/Elevator.h"

#include <algorithm>
#include <chrono>
#include <thread>

void Elevator::requestFloor(int floor)
{
    if (std::find(m_requests.begin(), m_requests.end(), floor) == m_requests.end())
    {
        m_requests.push_back(floor);
    }
    else
    {
        std::cout << "Floor " << floor << " has already been requested" << std::endl;
    }

    //sort the requests based on the current direction
    //of the elevator and process them
    switch (m_currentDirection)
    {
    case direction::STATIONARY:
        //if elevator is static, process the requests as is
        //since m_requests will ideally be empty
        break;
    case direction::DOWN:
    {
        //sort the requests such that floors lower than the current floor
        //are served in a top to bottom manner
        std::sort(m_requests.begin(), m_requests.end());
        auto firstRequest = std::upper_bound(m_requests.begin(), m_requests.end(), m_currentPosition);
        std::reverse(m_requests.begin(), firstRequest);
        break;
    }
    case direction::UP:
    {
        //sort the requests such that floors above the current floor
        //are served in a bottom to top manner
        std::sort(m_requests.begin(), m_requests.end(), std::greater<>());
        auto firstRequest = std::upper_bound(m_requests.begin(), m_requests.end(), m_currentPosition, std::greater<>());
        std::reverse(m_requests.begin(), firstRequest);
        break;
    }
    default:
        std::cout << "Something went wrong" << std::endl;
    }
    processRequests();
}

void Elevator::processRequests()
{
    while (!m_requests.empty())
    {
        if (m_requests.size() > 1)
        {
            if (*m_requests.begin() < *(m_requests.begin() + 1))
            {
                m_currentDirection = direction::UP;
            }
            else
            {
                m_currentDirection = direction::DOWN;
            }
        }
        else
        {
            m_currentDirection = direction::STATIONARY;
        }

        m_currentPosition = m_requests.front();
        m_requests.pop_front();
        printStatus();
    }
}

void Elevator::printStatus() const
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Elevator is at floor " << m_currentPosition << std::endl;
    if (m_currentDirection == direction::DOWN)
    {
        std::cout << "Elevator is going down" << std::endl;
    }
    else if (m_currentDirection == direction::UP)
    {
        std::cout << "Elevator is going up" << std::endl;
    }
    else
    {
        std::cout << "Elevator is stationary" << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
}