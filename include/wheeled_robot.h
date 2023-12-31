#pragma once

#include "mobile_robot.h"

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace RWA2{
/**
 * @brief Class for the Wheeledrobot and the derived type
 *
 */
class WheeledRobot : public MobileRobot {
 private:
   // Attributes
  //<! number of wheels
  int number_of_wheels_;
  //<! wheel diameter of the robot
  double wheel_diameter_;
  //<! desired speed of the robot
  double desired_speed_;

 public:
   /**
   * @brief Construct a new WheeledRobot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  WheeledRobot(double x, double y, double orientation, int current_charge, std::string robot_model,
    std::string battery_model, double wheel_diameter, double desired_speed, int number_of_wheels=2)
            : MobileRobot(x, y, orientation, current_charge, robot_model, battery_model),
              wheel_diameter_{wheel_diameter},
              desired_speed_{desired_speed} {
                if (robot_model == "Turtlebot") {
                  number_of_wheels_= number_of_wheels;
                }
                else if (robot_model == "Hiwonder") {
                  number_of_wheels_= 4;
                }
                else if (robot_model == "Dagu") {
                  number_of_wheels_= 6;
                }
                else {
                  number_of_wheels_= number_of_wheels;
                }
            }

  // ==================== methods ====================
  /**
   * @brief Move the robot by a given distance and angle
   *
   * @param distance distance to move
   * @param angle angle to move
   */
  virtual void move(double distance, double angle) override;

   /**
   * @brief Print the status of the robot
   */ 
  virtual void print_status() override;

 private:

   /**
   * @brief accelerate the robot by a given amount
   *
   * @param amount amount to be accelerated
   */
  void accelerate(double amount);

   /**
   * @brief Decelerate the robot by a given amount
   *
   * @param amount amount to be decelerated
   */
  void decelerate(double amount);

  /**
   * @brief Brake the robot
   */
  void brake();

 protected:
  /**
   * @brief Rotate the robot by a given angle
   *
   * @param angle angle to rotate (in degrees)
   */
  virtual void rotate(double angle) override;

 

  // ==================== accessors ==================== 
  /**
   * @brief Get the speed of the robot
   *
   * @return double
   */
  double get_actual_speed() const { return speed_; }

};
}

