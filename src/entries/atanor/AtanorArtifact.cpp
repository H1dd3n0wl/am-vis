#include "AtanorArtifact.hpp"

AtanorArtifact::AtanorArtifact(int id, const std::string& name,
                               const ArtifactSlot& slot,
                               const ItemRarity& rarity,
                               const std::string& description)
    : id_(id), name_(name), slot_(slot), rarity_(rarity),
      description_(description) {}

AtanorArtifact::AtanorArtifact()
    : AtanorArtifact(-1, "", ArtifactSlot::UNDEFINED, ItemRarity::UNDEFINED,
                     "") {}

int AtanorArtifact::get_id() { return id_; }

std::ostream& operator<<(std::ostream& os, const AtanorArtifact& artifact) {
    os << artifact.name_ << ":\nРедкость: " << artifact.rarity_
       << "\nСлот: " << artifact.slot_
       << "\nОписание: " << artifact.description_ << '\n';
    return os;
}
