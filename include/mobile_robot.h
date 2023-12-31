#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "battery.h"
#include "sensor.h"

/**
 * @brief Namespace for the rwa2 project
 *
 */
namespace RWA2 {
/**
 * @brief Class for the mobile robot
 *
 */
class MobileRobot {
 protected:
  // ==================== attributes ====================
  //<! position of the robot
  std::pair<double, double> position_;
  //<! orientation of the robot (in rad)
  double orientation_;
  //<! speed of the robot
  double speed_{0.0};
  //<! battery of the robot
  RWA2::Battery battery_;
  //<! list of sensors for the robot
  std::vector<std::unique_ptr<RWA2::Sensor>> sensors_;
  //<! model name of the robot
  std::string model_;

  // ==================== methods ====================
  /**
   * @brief Rotate the robot by a given angle
   *
   * @param angle angle to rotate (in degrees)
   */
  virtual void rotate(double angle);

 public:
  // ==================== constructors ====================
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot(std::string robot_model, std::string battery_model) : MobileRobot(0, 0, 0, 100, robot_model, battery_model) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  
  MobileRobot(double orientation, std::string robot_model, std::string battery_model)
     : MobileRobot(0, 0, orientation, 100, robot_model, battery_model) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot(double x, double y, std::string robot_model, std::string battery_model)
     : MobileRobot(x, y, 0, 100, robot_model, battery_model) {}
  /**
   * @brief Construct a new Mobile Robot object
   * @note This is a delegating constructor
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  MobileRobot(double x, double y, double orientation, std::string robot_model, std::string battery_model)
     : MobileRobot(x, y, orientation, 100, robot_model, battery_model) {}
  /**
   * @brief Construct a new Mobile Robot object
   * @note This is a delegating constructor
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot(double x, double y, double orientation, double battery_charge, std::string robot_model, std::string battery_model)
      : position_{x, y},
        orientation_{orientation},
        battery_{battery_model, battery_charge, false},
        model_{robot_model} {}
  /**
   * @brief Virtual Destructor to destroy the Mobile Robot object
   * 
   */
  virtual ~MobileRobot() {}

  // ==================== accessors ====================
  /**
   * @brief Get the position of the robot
   *
   * @return std::pair<double, double>
   */
  std::pair<double, double> get_position() const { return position_; }
  /**
   * @brief Get the orientation of the robot
   *
   * @return double
   */
  double get_orientation() const { return orientation_; }
  /**
   * @brief Get the speed of the robot
   *
   * @return double
   */
  double get_speed() const { return speed_; }

  /**
   * @brief Get the battery level of the robot
   *
   * @return double
   */
  double get_battery_level() const { return battery_.get_current_charge(); }

  // ==================== methods ====================
  /**
   * @brief move the robot as per the given parameters
   * 
   * @param distance 
   * @param angle 
   */
  virtual void move(double distance, double angle) = 0;
  /**
   * @brief Print the current position, orientation and speed of the robot
   *
   *
   *
   */
  virtual void print_status();
  /**
   * @brief Charge the robot's battery
   *
   * This method calls the Battery::start_charging() method
   *
   */
  void charge_battery();
  /**
   * @brief Add a sensor to the robot
   *
   * @param sensor sensor to add
   */
  void add_sensor(std::unique_ptr<RWA2::Sensor> sensor);

};  // class MobileRobot
}  // namespace RWA2
