#include "../../../include/headers.hpp"

namespace katalysti
{
    namespace items
    {
        CItem_Weapon_Test::CItem_Weapon_Test( void )
        {
            this->item_name = "Test Weapon";
            this->item_type = ItemType::WEAPON_1H;
        }
        void CItem_Weapon_Test::Tick( void )
        {
            std::cout << "Tick" << '\n';
        }
    }
}