#include "../../include/headers.hpp"

namespace katalysti
{
    namespace items
    {
        std::string_view IItemBase::GetItemName( void ) const
        {
            return std::string_view{ this->item_name };
        }
        ItemType IItemBase::GetItemType( void ) const
        {
            return this->item_type;
        }
    }
}