#pragma once

namespace katalysti
{
    namespace items
    {
       class CItem_Weapon_Test : public IItemBase
       {
            public:
                CItem_Weapon_Test( void );
            public:
                void Tick( void );
       };
    }
}