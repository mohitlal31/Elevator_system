#include <iostream>
#include <queue>

class Elevator
{
public:
  enum class direction
  {
    UP,
    DOWN,
    STATIONARY
  };

  Elevator(std::deque<int> requests, int currentPosition, direction currentDirection)
      : m_requests(requests),
        m_currentPosition(currentPosition),
        m_currentDirection(currentDirection) {}

  void requestFloor(int floor);
  void printStatus();

private:
  void processRequests();

  std::deque<int> m_requests;
  int m_currentPosition;
  direction m_currentDirection;
};