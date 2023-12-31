#include "aquatic_robot.h"
#include <thread>
#include <chrono>

// method implementation for diving.
// ======================================================================================================
void RWA2::AquaticRobot::dive(double depth) {
    if (is_diving_) {
        std::cout << "Already diving\n";
        return;
    }

    speed_ = has_fins_ ? 2.0 : 1.0 ;
    double time_to_dive = depth / speed_;

    // Emulate diving by sleeping
    std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(time_to_dive)));

    depth_ = depth;
    is_diving_ = true;

    std::cout << "AquaticRobot dived to a depth of " << depth_ << " meters\n";
}

// method implementation for surfacing.
// ======================================================================================================
void RWA2::AquaticRobot::surface() {

    if (!is_diving_) {
        std::cout << "Not diving\n";
        return;
    }

    speed_ = has_fins_ ? 4.0 : 2.0;
    double time_to_surface = depth_ / speed_;

    // Emulate surfacing by sleeping
    std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(time_to_surface)));

    depth_ = 0.0;
    speed_ = 0.0;
    is_diving_ = false;

    charge_battery();

    std::cout << "Surfaced. Battery fully recharged\n";
}

// method implementation for rotation
// ======================================================================================================
void RWA2::AquaticRobot::rotate(double angle){
  RWA2::MobileRobot::rotate(angle);
  std::cout << model_ << " rotated "<< angle <<" degrees.\n";
}

// method implementation for aquatic robot movement
// ======================================================================================================
void RWA2::AquaticRobot::move(double distance, double angle) {

    if (battery_.get_current_charge() < 2*distance) {
        std::cout << "Battery is too low to move by " << distance << " meters.\n";
        charge_battery();
    }

    for (auto &sensor : sensors_) {
    sensor->read_data(5);
    }
    rotate(angle);
    dive(distance / 2.0);
    surface();
    std::cout << model_ << " reached a depth of " << distance << " meters and then surfaced.\n";
    print_status();
}

// method implementation for state publication
// ======================================================================================================
void RWA2::AquaticRobot::print_status() {
    RWA2::MobileRobot::print_status();
    std::cout << "Depth: " << depth_ << "\tDiving Status: " << std::boolalpha << is_diving_ << ".\n";
    std::cout << "=================\n\n";
}






