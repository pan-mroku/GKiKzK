#include "inputmanager.hpp"
//#include <pair>
#include <string>
#include <boost/lexical_cast.hpp>

InputManager::InputManager(TinyOgre* ogre):OgreManager(ogre)
{
  size_t hWnd = 0;
  ogre->Window->getCustomAttribute("WINDOW", &hWnd);
  
  OIS::ParamList paramList;
  paramList.insert(std::make_pair(std::string("WINDOW"), boost::lexical_cast<std::string>(hWnd)));

  // insert the following lines right before calling mInputSystem = OIS::InputManager::createInputSystem( paramList );
#if defined OIS_WIN32_PLATFORM
  paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
  paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
#elif defined OIS_LINUX_PLATFORM
  paramList.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
  paramList.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
#endif

  OISInputManager = OIS::InputManager::createInputSystem(paramList);

  Mouse = static_cast<OIS::Mouse*>(OISInputManager->createInputObject(OIS::OISMouse, false));
  Keyboard = static_cast<OIS::Keyboard*>(OISInputManager->createInputObject(OIS::OISKeyboard, false));
}

