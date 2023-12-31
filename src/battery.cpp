#include "battery.h"

#include <chrono>
#include <thread>

void RWA2::Battery::stop_charging() {
  is_charging_ = false;
  std::cout << "Battery " << model_ << "is fully charged." << '\n';
}

// method implemetation for battery charging
// ======================================================================================================
void RWA2::Battery::start_charging() {
  // checking if battery is currently charging or not.
  if (!is_charging_) {
    std::cout << "Battery " << model_ << "is charging." << '\n';
    is_charging_ = true;

    // This is to calculate the remaining charging to be done.
    double to_charge = 100.0 - current_charge_;
    int charge_time{};

    if (model_ == "Li-ion") {
      charge_time = static_cast<int> (to_charge/100)*50;
    }
    else if (model_ == "LiFeP04") {
      charge_time = static_cast<int> (to_charge/100)*25;
    }

    // simulation of charging
    std::chrono::seconds duration(charge_time);
    std::this_thread::sleep_for(duration);
    stop_charging();
    current_charge_ = 100;
  }
  else {
    std::cout << "Battery is already charging." << '\n';
  }
}

// method implemetation for battery discharge
// ======================================================================================================
void RWA2::Battery::discharge(double amount) {
  current_charge_ -= amount;
  std::cout << "Current charge: " << current_charge_ << '\n';
}