#pragma once

namespace katalysti
{
    namespace character
    {
       class ICharacterBase
       {
          public:
            CharacterRace GetCharacterRace( void ) const;
          protected:
            CharacterRace race;
       };
    }
}