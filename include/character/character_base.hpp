#pragma once

namespace katalysti
{
    namespace character
    {
       constexpr auto AGE_MIN = 16;
       constexpr auto AGE_MAX = 50;
       
       class CCharacterBase
       {
          public:
            virtual ~CCharacterBase( void ) {}
            CCharacterBase( std::string_view character_name, const CharacterRace &character_race, const CharacterTeam &character_team, const uint16_t &character_age );
          public:
            uint16_t GetAttributePoints( const CharacterAttribute &a ) const;
            uint16_t GetCharacterAge( void ) const;
            std::string_view GetCharacterName( void ) const;
            CharacterRace GetCharacterRace( void ) const;
            CharacterTeam GetCharacterTeam( void ) const;
            void SetAttributePoint( const CharacterAttribute &a, const int &value );
          protected:
            void SetAgeModifiers( void );
            void SetRacialModifiers( void );
          protected:
            uint16_t age;
            std::array<CharacterAttribs_t, 5> attributes;
            std::string name;
            CharacterRace race;
            CharacterTeam team;
       };
    }
}