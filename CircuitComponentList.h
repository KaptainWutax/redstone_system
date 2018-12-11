//
// Created by joseph on 10/12/18.
//

#ifndef REDSTONE_SYSTEM_CIRCUITCOMPONENTLIST_H
#define REDSTONE_SYSTEM_CIRCUITCOMPONENTLIST_H

#include <vector>
#include "BlockPos.h"

class BaseCircuitComponent;

class CircuitComponentList {
public:
    class Item {
    public:
        BaseCircuitComponent *field_0;
        int field_8;
        BlockPos field_C;
        char field_18;
        bool field_19;
        int field_1C;

        Item(BaseCircuitComponent *component, int i, BlockPos *pos) :
            field_0(component),
            field_8(i),
            field_C(pos),
            field_18(6),
            field_19(false),
            field_1C(0) {
        }
        explicit Item(Item* other) :
            field_0(other->field_0),
            field_8(other->field_8),
            field_C(other->field_C),
            field_18(other->field_18),
            field_19(other->field_19),
            field_1C(other->field_1C) {
        }
    };
private:
    std::vector<Item> items;

public:
    void add(BaseCircuitComponent *component, int i, BlockPos *pos) {
        items.push_back(Item(component, i, pos));
    }

    auto begin() {
        return items.begin();
    }

    auto end() {
        return items.end();
    }

    auto erase(std::vector<Item>::iterator item) {
        return items.erase(item);
    }

    auto push_back(Item *item) {
        return items.push_back(Item(item));
    }

    bool removeSource(const BlockPos *a2, const BaseCircuitComponent *a3) {
        bool erasedAny = false;
        for (auto it = items.begin(); it != items.end();) {
            if (it->field_C == *a2) {
                it = items.erase(it);
                erasedAny = true;
            } else {
                ++it;
            }
        }
        return erasedAny;
    }

    auto size() {
        return items.size();
    }
};

#endif //REDSTONE_SYSTEM_CIRCUITCOMPONENTLIST_H