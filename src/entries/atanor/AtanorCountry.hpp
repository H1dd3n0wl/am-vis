#pragma once

#include <Element.hpp>
#include <sstream>

class AtanorCountry {
private:
    int id_;
    std::string name_;
    std::string species_;
    int money_;
    int army_;
    int magic_;
    int technology_;
    int friendliness_;
    int resources_;
    std::string topography_;
    std::string capital_;
    std::string description_;

    int get_cost(const std::string& str);

public:
    AtanorCountry(int id, const std::string& name, const std::string& species,
                  int money, int army, int magic, int technology,
                  int friendliness, int resources,
                  const std::string& topography, const std::string& capital,
                  const std::string& description);
    AtanorCountry();
    ~AtanorCountry() = default;

    int get_id();

    friend std::ostream& operator<<(std::ostream& os,
                                    const AtanorCountry& country);
};
