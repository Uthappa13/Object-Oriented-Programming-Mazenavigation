#pragma once

#include <iostream>
#include "mobile_robot.h"

/**
 * @brief 
 * 
 */
namespace RWA2 {
    /**
     * @brief 
     * 
     */
    class AerialRobot : public MobileRobot {
        private:
            // ==================== attributes ====================
            bool has_wings_;
            double altitude_;
            bool is_flying_;

            // ==================== methods ====================
            /**
             * @brief 
             * 
             * @param altitide 
             */
            void take_off(double altitide);
            /**
             * @brief 
             * 
             */
            void land();

        protected:
            // ==================== methods ====================
            /**
             * @brief 
             * 
             * @param angle 
             */
            virtual void rotate(double angle) override;
        
        public:
            // ==================== constructors ====================
            /**
             * @brief Construct a new Aerial Robot object
             * 
             * @param x 
             * @param y 
             * @param orientation 
             * @param battery_charge    
             * @param has_wings 
             * @param altitude 
             * @param is_flying 
             */
            AerialRobot(double x, double y, double orientation, double battery_charge, std::string robot_model,
                std::string battery_model, double altitude = 0.0, bool is_flying = false)
                    : MobileRobot(x, y, orientation, battery_charge, robot_model, battery_model),
                      altitude_{altitude},
                      is_flying_{is_flying} {
                        if (robot_model == "Erle-Plane") {
                            has_wings_ = true;
                        }
                        else {
                            has_wings_ = false;
                        }
                      }
            
            // ==================== methods ====================
            /**
             * @brief 
             * 
             * @param distance 
             * @param angle 
             */
            virtual void move(double distance, double angle) override;
            /**
             * @brief 
             * 
             */
            virtual void print_status() override;

    };  // class AerialRobot
}   // namespace RWA2