#pragma once
#include "mobile_robot.h"


namespace RWA2 {
class AquaticRobot: public MobileRobot{
    public:
        AquaticRobot(double x, double y, double orientation, double battery_charge, std::string robot_model,
            std::string battery_model, double depth=0.0, bool is_diving=false)
                : MobileRobot(x, y, orientation, battery_charge, robot_model, battery_model),
                depth_{depth},
                is_diving_{is_diving} {
                    if (robot_model == "SoFi") {
                        has_fins_ = true;
                    }
                    else {
                        has_fins_ = false;
                    }
                }
    
        //  virtual void rotate(double angle) override;
        //  virtual void move(double distance, double angle) override;
        //  virtual void print_status() override;
        virtual void move(double distance, double angle) override;
        virtual void print_status() override;

    protected:
        virtual void rotate(double angle) override;

    private:
        // ================ attributes =================
        bool has_fins_;
        double depth_;
        bool is_diving_;
        // ================ methods ==================
        void dive(double depth);
        void surface();

}; // class AquaticRobot
} // namespace RWA2