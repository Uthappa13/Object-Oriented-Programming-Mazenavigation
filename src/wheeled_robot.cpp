#include <chrono>
#include <thread>
#include <cmath>

#include "wheeled_robot.h"

// method implemetation for wheeled robot movement
//==============================================================================
void RWA2::WheeledRobot::move(double distance, double angle) {
  // each meter consumes 1% of the battery
  // check if the battery has enough charge to move the robot forward by the
  // given distance
  if (battery_.get_current_charge() < distance) {
    std::cout << "Battery level is too low to move forward by " << distance
              << " m\n";
    charge_battery();
  }

  for (auto &sensor : sensors_) {
    sensor->read_data(5);
  }

  rotate(angle);
  accelerate(2);
  std::chrono::seconds duration(2);
  std::this_thread::sleep_for(duration);
  decelerate(2);
  brake();
  position_.first = position_.first + distance*cos(angle);
  position_.second = position_.second + distance*sin(angle);
  std::cout << model_ << " drove " << distance << "m.\n";
  battery_.discharge(distance);
  print_status();
}

// method implementation for wheeled robot rotation
//==============================================================================
void RWA2::WheeledRobot::rotate(double angle) {
    RWA2::MobileRobot::rotate(angle);
    std::cout << model_ << " rotated " << angle << " degrees.";
}

// method implementation for wheeled robot acceleration
//==============================================================================
void RWA2::WheeledRobot::accelerate(double amount) {
    while((speed_ + amount) <= desired_speed_) {
      speed_ = speed_ + amount;
      std::chrono::microseconds duration(500);
      std::this_thread::sleep_for(duration);
    }
    std::cout << model_ <<" has reached the desired speed of "<< desired_speed_ <<"m/s.\n";    
}

// method implementation for wheeled robot deceleration
//==============================================================================
void RWA2::WheeledRobot::decelerate(double amount) {
    while((speed_ - amount) >= 0) {
      speed_ = speed_ - amount;
      std::chrono::microseconds duration(500);
      std::this_thread::sleep_for(duration);
    }
}

// method implementation for wheeled robot braking
//==============================================================================
void RWA2::WheeledRobot::brake() {
    speed_ = 0;
}

// method implementation for state publication
// ======================================================================================================
void RWA2::WheeledRobot::print_status() {
  RWA2::MobileRobot::print_status();
  std::cout << "Number of Wheels: " << number_of_wheels_ << " , Wheel Diameter: " << wheel_diameter_ << " , Desired Speed: " << desired_speed_ << "\n";
  std::cout << "=================\n\n";
}

