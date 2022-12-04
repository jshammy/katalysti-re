#include "../../include/headers.hpp"

namespace katalysti
{
    namespace character
    {        
        std::unique_ptr<CCharacterBase> GenerateRandomCharacter()
        {
            auto new_character = std::make_unique<CCharacterBase>("asdf", CharacterRace::DWARF, CharacterTeam::RECRUITABLE, 16);
            return new_character;
        }

        std::string GenerateRandomName( const CharacterRace &race )
        {
            std::array<const char*, 20> first_names, last_names;

            switch( race )
            {
                case CharacterRace::DWARF:
                    first_names = DWARF_FIRST_NAME;
                    last_names  = DWARF_LAST_NAME;
                    break;
                case CharacterRace::ELF:
                    first_names = ELF_FIRST_NAME;
                    last_names  = ELF_LAST_NAME;
                    break;
                case CharacterRace::HUMAN:
                    first_names = HUMAN_FIRST_NAME;
                    last_names  = HUMAN_LAST_NAME;
                    break;
                case CharacterRace::ORC:
                    first_names = ORC_FIRST_NAME;
                    last_names  = ORC_LAST_NAME;
                    break;
                case CharacterRace::TROLL:
                case CharacterRace::UNDEAD:
                    first_names = UNDEAD_FIRST_NAME;
                    last_names  = UNDEAD_LAST_NAME;
                    break;
                default:
                    std::fill( first_names.begin(), first_names.end(), "Invalid");
                    std::fill( last_names.begin(), last_names.end(), "Invalid");
                    break;
            }
            
            std::random_device rand_dev;
            std::mt19937 rand_engine(rand_dev());
            std::uniform_int_distribution<int> val(0,last_names.size() - 1);

            const auto rand_index0 = val( rand_engine );
            const auto rand_index1 = val( rand_engine );

            std::string rand_first = first_names[rand_index0];
            std::string rand_last  = last_names[rand_index1];

            return std::string( rand_first + " " + rand_last );
        }

        std::string_view RaceAsString( const CharacterRace &race )
        {
            switch( race )
            {
                case CharacterRace::DWARF:
                    return "Dwarf";
                case CharacterRace::HUMAN:
                    return "Human";
                case CharacterRace::ELF:
                    return "Elf";
                case CharacterRace::ORC:
                    return "Orc";
                case CharacterRace::TROLL:
                    return "Troll";
                case CharacterRace::UNDEAD:
                    return "Undead";
                default:
                    return "Invalid CharacterRace";
            }
        }
    }
}