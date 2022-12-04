#include "../include/headers.hpp"

int main( void )
{
    const auto char_test = katalysti::character::GenerateRandomCharacter(false);

    std::cout << "name: " << char_test->GetCharacterName() << '\n';
    std::cout << "race: " << katalysti::character::RaceAsString( char_test->GetCharacterRace() ) << '\n';
    std::cout << "age: " << char_test->GetCharacterAge() << '\n';
    std::cout << "dex: " << char_test->GetAttributePoints( katalysti::character::CharacterAttribute::DEXTERITY ) << '\n';
    std::cout << "int: " << char_test->GetAttributePoints( katalysti::character::CharacterAttribute::INTELLIGENCE ) << '\n';
    std::cout << "sta: " << char_test->GetAttributePoints( katalysti::character::CharacterAttribute::STAMINA ) << '\n';
    std::cout << "str: " << char_test->GetAttributePoints( katalysti::character::CharacterAttribute::STRENGTH ) << '\n';
    std::cout << "wis: " << char_test->GetAttributePoints( katalysti::character::CharacterAttribute::WISDOM ) << '\n';
}