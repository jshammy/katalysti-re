#pragma once

namespace katalysti
{
    namespace character
    {
        enum class CharacterAttribute : unsigned
        {
            DEXTERITY,
            INTELLIGENCE,
            STAMINA,
            STRENGTH,
            WISDOM,
            NUM_ATTRIBUTES
        };        
        using CharacterAttribs_t = std::pair<CharacterAttribute, uint16_t>;
    }
}