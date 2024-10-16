#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class ArtifactSlot {
public:
    enum Value {
        HEAD,
        NECK,
        SHOULDERS,
        BACK,
        FIRST_ARM,
        SECOND_ARM,
        LEFT_RING,
        RIGHT_RING,
        FEET,
        OBJECT_1,
        OBJECT_2,
        OBJECT_3,
        UNDEFINED
    };

    ArtifactSlot() = default;
    ArtifactSlot(Value slot);
    ArtifactSlot(const std::string& slot);
    ~ArtifactSlot() = default;

    constexpr bool operator==(const ArtifactSlot& other) const;
    constexpr bool operator!=(const ArtifactSlot& other) const;

    friend std::ostream& operator<<(std::ostream& os, const ArtifactSlot& slot);

private:
    std::string to_string() const;

    Value value = Value::UNDEFINED;
};
