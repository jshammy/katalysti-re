#pragma once

namespace katalysti
{
    namespace character
    {
        constexpr auto AGE_INCREMENT = 1;

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