#include "ArtifactSlot.hpp"

ArtifactSlot::ArtifactSlot(Value slot) : value(slot) {}

ArtifactSlot::ArtifactSlot(const std::string& slot) {
    std::unordered_map<std::string, Value> mapping = {
        {"Голова", Value::HEAD},
        {"Шея", Value::NECK},
        {"Плечи", Value::SHOULDERS},
        {"Спина", Value::BACK},
        {"Первая рука", Value::FIRST_ARM},
        {"Вторая рука", Value::SECOND_ARM},
        {"Кольцо на левую руку", Value::LEFT_RING},
        {"Кольцо на правую руку", Value::RIGHT_RING},
        {"Ноги", Value::FEET},
        {"Предмет 1", Value::OBJECT_1},
        {"Предмет 2", Value::OBJECT_2},
        {"Предмет 3", Value::OBJECT_3}};

    if (!mapping.contains(slot)) {
        value = Value::UNDEFINED;
    }
    value = mapping[slot];
}

constexpr bool ArtifactSlot::operator==(const ArtifactSlot& other) const {
    return value == other.value;
}

constexpr bool ArtifactSlot::operator!=(const ArtifactSlot& other) const {
    return value != other.value;
}

std::string ArtifactSlot::to_string() const {
    switch (value) {
    case HEAD:
        return "Голова";
    case NECK:
        return "Шея";
    case SHOULDERS:
        return "Плечи";
    case BACK:
        return "Спина";
    case FIRST_ARM:
        return "Первая рука";
    case SECOND_ARM:
        return "Вторая рука";
    case LEFT_RING:
        return "Кольцо на левую руку";
    case RIGHT_RING:
        return "Кольцо на правую руку";
    case FEET:
        return "Ноги";
    case OBJECT_1:
        return "Предмет 1";
    case OBJECT_2:
        return "Предмет 2";
    case OBJECT_3:
        return "Предмет 3";
    default:
        return "UNDEFINED";
    }
}

std::ostream& operator<<(std::ostream& os, const ArtifactSlot& slot) {
    os << slot.to_string();
    return os;
}
