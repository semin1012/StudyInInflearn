#include <iostream>
#include "Item.h"
#include "Inventory.h"
using namespace std;

// [시스템] 몬스터를 잡을 때, 아이템을 떨군다.
Item* DropItem()
{
    if (rand() % 2 == 0)
    {
        Weapon* weapon = new Weapon();
        return weapon;
    }
    else
    {
        Armor* armor = new Armor();
        return armor;
    }
}

int main()
{
    srand((unsigned)time(0));


    // 몬스터 처치
    for (int i = 0; i < 100; i++)
    {
        Item* item = DropItem();
        item->PrintInfo();

        ItemType itemType = item->GetItemType();
        if (itemType == IT_Weapon)
        {
            Weapon* weapon = static_cast<Weapon*>(item);
        }

        // Weapon* weapon = dynamic_cast<Weapon*>(item); // 위와 같은 방식이다. static_cast 대신 dynamic_cast
        // 그렇지만 dynamic_cast가 조금 더 느리다는 결과가 있어서 민감한 경우 잘 안 쓴다. 매 프레임마다 쓰는 경우는 아니라면 써도 괜찮다.

        if (Inventory::GetInstance()->AddItem(item))
        {
            cout << "Added Item to Inven" << endl;
        }
        else
        {
            cout << "Failed to add Item" << endl;
            delete item;
        }
    }

    // PK 당해서 랜덤으로 일부 아이템 드랍
    for (int i = 0; i < 20; i++) 
    {
        int randIndex = rand() % MAX_SLOT;
        Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);
        if (item && Inventory::GetInstance()->RemoveItem(item))   
                cout << "Removed Item" << endl;
    }

        /*ItemType itemType = item->GetItemType();
        if (itemType == IT_Weapon)
        {
            Weapon* weapon = (Weapon*)item;
            weapon->GetDamage();
        }
        else if (itemType == IT_Armor)
        {
            Armor* armor = (Armor*)item;
            armor->GetDefence();
        }       */ 

        // delete item

}