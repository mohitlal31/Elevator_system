#include <vector>
#include <iostream>

class Elevator;

const int FLOORS = 10;

class Controller
{
public:
  enum class m_button
  {
    UP,
    DOWN
  };

  Controller(Elevator &elevator, int floors) : m_elevator(elevator), m_floors(floors){};

  void requestElevator(int currentFloor, m_button direction);

private:
  std::vector<m_button> m_requests;
  Elevator &m_elevator;
  int m_floors;
};