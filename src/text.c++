#include "text.h"

void Heatforge::Text::Draw()
{
    font -> Draw(&intArray, &position);
}

void Heatforge::Text::ChangeText(std::wstring text)
{
    intArray = engine -> ConvertStringToIntArray(text);
}