#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "aerial_robot.h"
#include "aquatic_robot.h"
#include "wheeled_robot.h"
#include "legged_robot.h"

void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>>& robots) {
  for (const auto& robot : robots) {
    robot->move(14, 45);
  }
}

int main() {
  std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;

  std::unique_ptr<RWA2::MobileRobot> aerial_ptr = std::make_unique<RWA2::AerialRobot>(1, 1, 30, 10, "Erle-Plane", "Li-ion");
  std::unique_ptr<RWA2::MobileRobot> aquatic_ptr = std::make_unique<RWA2::AquaticRobot>(2, 2, 45, 70, "SoFi", "LiFeP04");
  std::unique_ptr<RWA2::MobileRobot> wheeled_ptr = std::make_unique<RWA2::WheeledRobot>(1, 1, 30, 90, "Turtlebot", "Li-ion", 2, 10);
  std::unique_ptr<RWA2::MobileRobot> legged_ptr = std::make_unique<RWA2::LeggedRobot>(1, 1, 30, 90, "Spot", "LiFeP04", 2, 2);

  aerial_ptr->add_sensor(std::make_unique<RWA2::Sensor>("OSDome"));
  aquatic_ptr->add_sensor(std::make_unique<RWA2::Sensor>("multiScan100"));
  wheeled_ptr->add_sensor(std::make_unique<RWA2::Sensor>("LD-MRS"));
  legged_ptr->add_sensor(std::make_unique<RWA2::Sensor>("OS2"));

  mobile_robots.push_back(std::move(aerial_ptr));
  mobile_robots.push_back(std::move(aquatic_ptr));
  mobile_robots.push_back(std::move(wheeled_ptr));
  mobile_robots.push_back(std::move(legged_ptr));

  move_robot(mobile_robots);
}