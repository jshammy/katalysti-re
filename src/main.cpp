#include "../include/headers.hpp"

int main( void )
{
    const auto item_test = std::make_unique<katalysti::items::CItem_Weapon_Test>();

    item_test->Tick();
    std::cout << item_test->GetItemName() << '\n';
}