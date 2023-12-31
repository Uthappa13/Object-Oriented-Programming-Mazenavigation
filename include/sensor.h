#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <utility>

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace RWA2 {
/**
 * @brief Class for the sensor
 *
 */
class Sensor {
 private:
  // ==================== attributes ====================
  std::string model_;
  std::array<double, 50> data_{};

 public:
  // ==================== constructors ====================
  Sensor(std::string sensor_name) : model_{sensor_name} {}

  // ==================== methods ====================
  /**
   * @brief Start reading the sensor data
   *
   * @param duration Period of the reading (in s)
   */
  void read_data(unsigned int duration);

};  // class Sensor
}  // namespace RWA2
