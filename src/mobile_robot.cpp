#include "mobile_robot.h"

#include <chrono>
#include <thread>

// method implementation for battery charging
//==============================================================================
void RWA2::MobileRobot::charge_battery() {
  battery_.start_charging();
}

// method implementation for base class rotation
//==============================================================================
void RWA2::MobileRobot::rotate(double angle) {
  // if angle is positive, it gets added to orientation
  // if angle is negetive it gets subtracted from orientation
  orientation_ = orientation_ + angle;
}

// method implementation for base class state publication
//==============================================================================
void RWA2::MobileRobot::print_status() {
  std::cout
      << "Position: (" << position_.first << ", "
      << position_.second << "), Orientation: " << orientation_
      << ", Speed: " << speed_ << ", Battery Charge: " << battery_.get_current_charge() << "\n";
}

// method implementation for adding sensors
//==============================================================================
void RWA2::MobileRobot::add_sensor(
    std::unique_ptr<RWA2::Sensor> sensor) {
  sensors_.push_back(std::move(sensor));
}