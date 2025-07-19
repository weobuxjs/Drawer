#pragma one
#include "../Entity.h"
#include <vector>
#include "Button.h"
class Pop_Up : public Entity
{
public:
    Pop_Up(int x, int y, int w, int h, std::vector<Button> buttons);
    std::vector<Button>& GetButtonsList();
private:
    std::vector<Button> buttonsList;
};