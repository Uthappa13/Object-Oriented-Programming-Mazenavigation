#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace RWA2 {
/**
 * @brief Class for the battery
 *
 */
class Battery {
 private:
  // ==================== attributes ====================
  /*< Capacity*/
  std::string model_;
  double current_charge_;
  bool is_charging_;
  // ==================== methods ====================
  /**
   * @brief Stop charging the battery
   *
   */
  void stop_charging();

 public:
  // ==================== constructors ====================
  Battery(std::string model, double current_charge, bool is_charging)
      : model_{model},
        current_charge_{current_charge},
        is_charging_{is_charging} {}

  // ==================== accessors ====================
  /**
   * @brief Get the capacity of the battery
   *
   * @return double
   */
  double get_current_charge() const { return current_charge_; }

  // ==================== methods ====================
  /**
   * @brief Start charging the battery
   *
   */
  void start_charging();
  /**
   * @brief Discharge the battery
   *
   * Each time the robot moves, the battery discharges by 1 percent
   */
  void discharge(double decrement);

};  // class Battery
}  // namespace RWA2
