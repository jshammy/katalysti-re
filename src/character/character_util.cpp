#include "../../include/headers.hpp"

namespace katalysti
{
    namespace character
    {
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