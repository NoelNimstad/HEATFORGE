#include "ltext.h"

void Heatforge::LText::Draw()
{
    font -> Draw(&intArray, &position);
}

void Heatforge::LText::ChangeText(std::wstring text)
{
    intArray = engine -> ConvertStringToIntArray(text);
}