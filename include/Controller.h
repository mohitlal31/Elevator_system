#include <vector>
#include <iostream>

class Elevator;

const int FLOORS = 10;

class Controller
{
  private:
    enum class m_button
    {
        UP,
        DOWN
    };

    Elevator &m_elevator;
    int m_floors;

  public:
    Controller(Elevator &elevator, int floors) : m_elevator(elevator), m_floors(floors){};

    void requestElevator(int currentFloor, m_button direction);

    //This should be private. For the purpose of demo using console, I've made it public
    std::vector<m_button> m_requests;
};