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
class LeggedRobot : public MobileRobot {
 private:
   // Attributes
  //<! height of the robot
  double height_;
  //<! Leg strength of the robot
  int leg_strength_;
  //<! number of legs of the robot
  int number_of_legs_;

 public:
   /**
   * @brief Construct a new LeggedRobot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  LeggedRobot(double x, double y, double orientation, int current_charge, std::string robot_model,
    std::string battery_model, double height, int leg_strength, int number_of_legs = 2)
            : MobileRobot(x, y, orientation, current_charge, robot_model, battery_model),
              height_{height},
              leg_strength_{leg_strength} {
                if (robot_model == "Atlas") {
                  number_of_legs_ = number_of_legs;
                }
                else if (robot_model == "Spot") {
                  number_of_legs_ = 4;
                }
                else if (robot_model == "Mx-Phoenix") {
                  number_of_legs_ = 6;
                }
                else {
                  number_of_legs_ = number_of_legs;
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
   * @brief Kick of the leggedrobot
   */
  void kick();

   /**
   * @brief Jump of the robot by a given amount
   *
   * @param amount amount to jump
   */
  void jump(double amount);

 protected:
  /**
   * @brief Rotate the robot by a given angle
   *
   * @param angle angle to rotate (in degrees)
   */
  virtual void rotate(double angle) override;

 

  // ==================== accessors ==================== 
  /**
   * @brief Get the height of the robot
   *
   * @return double
   */
  double get_height() const { return height_; }

  /**
   * @brief Get the leg strength of the robot
   *
   * @return int
   */
  int get_leg_strength() const { return leg_strength_; }  

};
}

