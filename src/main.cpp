#include "../include/headers.hpp"

int main( void )
{
    const auto item_test = std::make_unique<katalysti::items::CItem_Weapon_Test>();
    const auto char_test = std::make_unique<katalysti::character::ICharacterBase>();

    item_test->Tick();
    std::cout << item_test->GetItemName() << '\n';
    std::cout << katalysti::character::RaceAsString( char_test->GetCharacterRace() ) << '\n';
}