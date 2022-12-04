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
            const int character_age   = this->age;

            for( auto &attribute : attributes )
            {
                if( character_age == AGE_MIN )
                    break;
               
                for( auto i = AGE_MIN; i < character_age; i++ )
                    attribute.second += AGE_INCREMENT;
            }
        }

        void CCharacterBase::SetAttributePoint( const CharacterAttribute &a, const int &value )
        {
            this->attributes[static_cast<int>(a)].second = value;
        }

        void CCharacterBase::SetRacialModifiers( void )
        {
            const auto character_race = this->race;
            
            switch( character_race )
            {
                case CharacterRace::DWARF:
                    SetAttributePoint( CharacterAttribute::DEXTERITY, 16 );
                    SetAttributePoint( CharacterAttribute::INTELLIGENCE, 19 );
                    SetAttributePoint( CharacterAttribute::STAMINA, 23 );
                    SetAttributePoint( CharacterAttribute::STRENGTH, 22 );
                    SetAttributePoint( CharacterAttribute::WISDOM, 19 );
                    break;
                case CharacterRace::ELF:
                    SetAttributePoint( CharacterAttribute::DEXTERITY, 25 );
                    SetAttributePoint( CharacterAttribute::INTELLIGENCE, 20 );
                    SetAttributePoint( CharacterAttribute::STAMINA, 19 );
                    SetAttributePoint( CharacterAttribute::STRENGTH, 17 );
                    SetAttributePoint( CharacterAttribute::WISDOM, 20 );
                    break;
                case CharacterRace::HUMAN:
                    SetAttributePoint( CharacterAttribute::DEXTERITY, 20 );
                    SetAttributePoint( CharacterAttribute::INTELLIGENCE, 20 );
                    SetAttributePoint( CharacterAttribute::STAMINA, 20 );
                    SetAttributePoint( CharacterAttribute::STRENGTH, 20 );
                    SetAttributePoint( CharacterAttribute::WISDOM, 21 );
                    break;
                case CharacterRace::ORC:
                    SetAttributePoint( CharacterAttribute::DEXTERITY, 17 );
                    SetAttributePoint( CharacterAttribute::INTELLIGENCE, 17 );
                    SetAttributePoint( CharacterAttribute::STAMINA, 22 );
                    SetAttributePoint( CharacterAttribute::STRENGTH, 23 );
                    SetAttributePoint( CharacterAttribute::WISDOM, 23 );
                    break;
                case CharacterRace::TROLL:
                    SetAttributePoint( CharacterAttribute::DEXTERITY, 22 );
                    SetAttributePoint( CharacterAttribute::INTELLIGENCE, 16 );
                    SetAttributePoint( CharacterAttribute::STAMINA, 21 );
                    SetAttributePoint( CharacterAttribute::STRENGTH, 21 );
                    SetAttributePoint( CharacterAttribute::WISDOM, 21 );
                    break;
                case CharacterRace::UNDEAD:
                    SetAttributePoint( CharacterAttribute::DEXTERITY, 18 );
                    SetAttributePoint( CharacterAttribute::INTELLIGENCE, 18 );
                    SetAttributePoint( CharacterAttribute::STAMINA, 21 );
                    SetAttributePoint( CharacterAttribute::STRENGTH, 19 );
                    SetAttributePoint( CharacterAttribute::WISDOM, 25 );
                    break;
                default:
                    break;
            }
        }
    }
}