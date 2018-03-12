#include "nwnx"

const string NWNX_Item = "NWNX_Item";

// Sets the provided item's current weight to the provided value.
void NWNX_Item_SetWeight(object oItem, int w);

void NWNX_Item_SetWeight(object oItem, int w)
{
    string sFunc = "SetWeight";

    NWNX_PushArgumentInt(NWNX_Item, sFunc, w);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
}

