
#include "legged_robot.h"
#include <iostream>
#include <cmath>

// method implemetation for legged robot movement
// ======================================================================================================
void RWA2::LeggedRobot::move(double distance, double angle) {
  // each centimeter jump consumes 1% of the battery
  // each kick consumes 1% battery per leg_strength
  // check if the battery has enough charge for one jump and one kick
  // given distance
  height_ = distance * leg_strength_;
  if (battery_.get_current_charge() < height_ + leg_strength_) {
    std::cout << "Battery level is too low\n";
    std::cout<< "Charging battery\n";
    charge_battery();
  }

  // reading sensor data
  for (auto &sensor : sensors_) {
      sensor->read_data(5);
  }

  rotate(angle);
  jump(distance);
  kick();
  position_.first = position_.first + distance*cos(angle);
  position_.second = position_.second + distance*sin(angle);
  battery_.discharge(height_ + leg_strength_);
  print_status();
}

// method implementation for legged robot kicking
// ======================================================================================================
void RWA2::LeggedRobot::kick(){

    std::cout<<"The robot kicks with a strength of "<<leg_strength_<<"\n";    
}

// method implementation for legged robot jumping
// ======================================================================================================
void RWA2::LeggedRobot::jump(double amount) {
    std::cout<<"Initiating jump\n";
    std::chrono::seconds duration(2);
    std::this_thread::sleep_for(duration);
    height_ = amount * leg_strength_;
    std::cout << model_ << " jumps at a height of  "<< height_<<" cm above the ground\n";
}

// method implementation for aquatic robot movement
// ======================================================================================================
void RWA2::LeggedRobot::rotate(double angle) {
    std::cout << model_ << " rotated by "<< angle <<" degrees\n";
}

// method implementation for state publication
// ======================================================================================================
void RWA2::LeggedRobot::print_status(){
  RWA2::MobileRobot::print_status();
  std::cout << "=================\n\n";
}

