#include "../include/headers.hpp"

int main( void )
{
    const auto item_test = std::make_unique<katalysti::items::CItem_Weapon_Test>();
    const auto char_test = std::make_unique<katalysti::character::CCharacterBase>(
        "Sample Character", 
        katalysti::character::CharacterRace::UNDEAD, 
        katalysti::character::CharacterTeam::PLAYER,
        32);

    item_test->Tick();
    std::cout << item_test->GetItemName() << '\n';
    std::cout << katalysti::character::RaceAsString( char_test->GetCharacterRace() ) << '\n';
    std::cout << "name: " << char_test->GetCharacterName() << '\n';
    std::cout << "int: " << char_test->GetAttributePoints( katalysti::character::CharacterAttribute::INTELLIGENCE ) << '\n';
    std::cout << "age: " << char_test->GetCharacterAge() << '\n';

    std::cout << katalysti::character::GenerateRandomName(char_test->GetCharacterRace()) << '\n';
}