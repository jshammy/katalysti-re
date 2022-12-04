#pragma once

namespace katalysti
{
    namespace character
    {
        extern std::unique_ptr<CCharacterBase> GenerateRandomCharacter( const bool &recruitable );
        extern std::string GenerateRandomName( const CharacterRace &race );
        extern std::string_view RaceAsString( const CharacterRace &race );
    }
}
