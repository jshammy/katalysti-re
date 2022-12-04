#include "../../include/headers.hpp"

namespace katalysti
{
    namespace character
    {
        CCharacterBase::CCharacterBase( std::string_view character_name, const CharacterRace &character_race, const CharacterTeam &character_team, const uint16_t &character_age )
        {
            // base values
            this->attributes = {
                CharacterAttribs_t( CharacterAttribute::DEXTERITY, 20 ),
                CharacterAttribs_t( CharacterAttribute::INTELLIGENCE, 20 ),
                CharacterAttribs_t( CharacterAttribute::STAMINA, 20 ),
                CharacterAttribs_t( CharacterAttribute::STRENGTH, 20 ),
                CharacterAttribs_t( CharacterAttribute::WISDOM, 20 )
            };

            this->age  = character_age;
            this->name = character_name;
            this->race = character_race;
            this->team = character_team;

            SetRacialModifiers();
            SetAgeModifiers();
        }

        uint16_t CCharacterBase::GetAttributePoints( const CharacterAttribute &a  ) const
        {
            auto attribute_index = static_cast<std::size_t>(a);

            if( attribute_index < 0 || attribute_index > static_cast<std::size_t>(CharacterAttribute::NUM_ATTRIBUTES) )
                return static_cast<uint16_t>(0);

            const auto attribute = this->attributes[attribute_index].second;
            
            return attribute;
        }

        uint16_t CCharacterBase::GetCharacterAge( void ) const
        {
            return this->age;
        }

        std::string_view CCharacterBase::GetCharacterName( void ) const
        {
            return this->name;
        }

        CharacterRace CCharacterBase::GetCharacterRace( void ) const
        {
            return this->race;
        }

        CharacterTeam CCharacterBase::GetCharacterTeam( void ) const
        {
            return this->team;
        }

        void CCharacterBase::SetAgeModifiers( void )
        {
            const auto base_value     = 20;
            const int character_age   = this->age;

            for( auto &attribute : attributes )
            {
                if( character_age == AGE_MIN )
                    break;
               
                for( auto i = AGE_MIN; i < character_age; i++ )
                    attribute.second += 2;
            }
        }

        void CCharacterBase::SetRacialModifiers( void )
        {
            const auto character_race = this->race;
            
            switch( character_race )  // TODO
            {
                case CharacterRace::DWARF:
                case CharacterRace::ELF:
                case CharacterRace::HUMAN:
                case CharacterRace::ORC:
                case CharacterRace::TROLL:
                case CharacterRace::UNDEAD:
                default:
                    break;
            }
        }
    }
}