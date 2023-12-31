#include "sensor.h"

#include <chrono>
#include <random>

// method implementation for reading data
//==============================================================================
void RWA2::Sensor::read_data(unsigned int duration) {

    std::cout << "Starting reading from sensor " << model_ << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    //generate random double between 1 and 100
    std::random_device rd;  // Random device engine, usually based on
                            // /dev/urandom on UNIX-like OSes
    std::mt19937 gen(rd());  // Initializes with the random device
    std::uniform_real_distribution<> dis(0.0, 30.0);
    for (size_t i{0}; i < 50; ++i) {
        data_.at(i) = dis(gen);
    }
    std::cout << "Sensor " << model_ << " gathering data for " << duration << "seconds.\n";
}