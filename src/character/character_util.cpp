#include "../../include/headers.hpp"

namespace katalysti
{
    namespace character
    {
        constexpr auto AGE_MIN = 16;
        constexpr auto AGE_MAX = 50;
        
        std::unique_ptr<CCharacterBase> GenerateRandomCharacter()
        {
            auto new_character = std::make_unique<CCharacterBase>("asdf", CharacterRace::DWARF, CharacterTeam::RECRUITABLE, 16);
            return new_character;
        }

        std::string_view GenerateRandomName( const CharacterRace &race )
        {
            std::array<const char*, 20> first_names, last_names;

            switch( race )
            {
                case CharacterRace::DWARF:
                    first_names = DWARF_FIRST_NAME;
                    last_names  = DWARF_LAST_NAME;
                    break;
                case CharacterRace::ELF:
                case CharacterRace::HUMAN:
                case CharacterRace::ORC:
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
            std::uniform_int_distribution<int> val(1,last_names.size() - 1);

            const auto random_index0 = val( rand_engine );
            const auto random_index1 = val( rand_engine );

            std::cout << "f: " << random_index0 << " l: " << random_index1 << '\n';
            std::string random_first = first_names[random_index0];
            std::string random_last  = last_names[random_index1];

            return std::string_view( random_first + " " + random_last );
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