#include "text.h"

void Heatforge::Text::Draw()
{
    font -> Draw(&intArray, &position);
}

void Heatforge::Text::ChangeText(std::string text)
{
    intArray = engine -> ConvertStringToIntArray(text);
}