#include "Pop_Up.h"
Pop_Up::Pop_Up(int x, int y, int w, int h, std::vector<Button> buttons) : Entity(x, y, w, h, NULL)
{
    buttonsList = buttons;
}
std::vector<Button>& Pop_Up::GetButtonsList()
{
    return buttonsList;
}