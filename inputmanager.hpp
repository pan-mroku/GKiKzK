#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <OIS.h>
#include "TinyOgre.hpp"

class InputManager
{
public:
  TinyOgre* OgreManager;
  OIS::InputManager* OISInputManager;
  OIS::Mouse* Mouse;
  OIS::Keyboard* Keyboard;

  InputManager(TinyOgre* ogre);
};

#endif
