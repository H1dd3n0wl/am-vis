#pragma once

#include <ArtifactSlot.hpp>
#include <ItemRarity.hpp>
#include <vector>

class AtanorArtifact {
private:
    int id_;
    std::string name_;
    ArtifactSlot slot_;
    ItemRarity rarity_;
    std::string description_;

public:
    AtanorArtifact(int id, const std::string& name, const ArtifactSlot& slot,
                   const ItemRarity& rarity, const std::string& description);
    AtanorArtifact();
    ~AtanorArtifact() = default;

    int get_id();

    friend std::ostream& operator<<(std::ostream& os,
                                    const AtanorArtifact& artifact);
};
