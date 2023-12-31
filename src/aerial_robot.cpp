#include <chrono>
#include <thread>

#include "aerial_robot.h"


// method implementation for take_off.
//==============================================================================
void RWA2::AerialRobot::take_off(double altitude) {

    // flight time calculation
    int flight_time{};
    if (!is_flying_) {
        if (has_wings_) {
            speed_ = 3;
            flight_time = static_cast<int> ((altitude - altitude_)/speed_);
        }
        else {
            speed_ = 1.5;
            flight_time = static_cast<int> ((altitude - altitude_)/speed_);
        }

        std::chrono::seconds duration(flight_time);
        std::this_thread::sleep_for(duration);
        altitude_ = altitude;
        is_flying_ = true;
    }
    else {
        std::cout << model_ << " is already flying.";
    }
}


// method implementation for land.
//==============================================================================
void RWA2::AerialRobot::land() {

    // flight time calculation
    int flight_time{};
    if (is_flying_) {
        if (has_wings_) {
            speed_ = 4;
            flight_time = static_cast<int> (altitude_/speed_);
        }
        else {
            speed_ = 2;
            flight_time = static_cast<int> (altitude_/speed_);
        }

        std::chrono::seconds duration(flight_time);
        std::this_thread::sleep_for(duration);
        altitude_ = 0.0;
        speed_ = 0.0;
        is_flying_ = false;
    }
    else {
        std::cout << model_ << " is on the ground.";
    }
}


// method implementation for rotate
//==============================================================================
void RWA2::AerialRobot::rotate(double angle) {
    RWA2::MobileRobot::rotate(angle);
    std::cout << model_ << " rotated " << angle << " degrees.\n";
}


// method implementation for print_status
//==============================================================================
void RWA2::AerialRobot::print_status() {
    RWA2::MobileRobot::print_status();
    std::cout << "Altitude: " << altitude_ << "\tFlying Status: " << std::boolalpha << is_flying_ << '\n';
    std::cout << "=================\n\n";
}


// method implementation for move
//==============================================================================
void RWA2::AerialRobot::move(double distance, double angle) {

    // checking for battery charge availability
    if (battery_.get_current_charge() < 2*distance) {
        std::cout << "Battery is too low to move by " << distance << " meters.\n";
        RWA2::MobileRobot::charge_battery();
    }

    // reading sensor data
    for (auto &sensor : sensors_) {
        sensor->read_data(5);
    }
    take_off(distance/2);
    rotate(angle);
    land();
    std::cout << model_ << " reached an altitude of " << distance << " meters and then landed.\n";
    battery_.discharge(2*distance);
    print_status();
}