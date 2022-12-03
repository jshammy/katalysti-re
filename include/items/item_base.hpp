#pragma once

namespace katalysti
{
    namespace items
    {
       class IItemBase
       {
            public:
                virtual ~IItemBase( void ) {};
            public:
                std::string_view GetItemName( void ) const;
                ItemType GetItemType( void ) const;
                virtual void Tick( void ) = 0;
            protected:
                std::string item_name;
                ItemType item_type;
       };
    }
}