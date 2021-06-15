#pragma once
class Element
{
public:
Element* prev;
Element* next;
int value;
Element() { prev = nullptr; next = nullptr; value = 0; };
};