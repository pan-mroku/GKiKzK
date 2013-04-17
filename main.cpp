#include "TinyOgre.hpp"
#include "inputmanager.hpp"
#include "suzanne.hpp"
#include <iostream>
#include <list>
#include <OgreEntity.h>
#include <OgreWindowEventUtilities.h>

std::list<Suzanne> MonkeyList;

uint events(InputManager& inputManager, TinyOgre& ogre) //@HACK:InputManager powinien wysyłać zdarzenia i mieć listenerów
{
  inputManager.Keyboard->capture();
  inputManager.Mouse->capture();
  
  //Wyjście z aplikacji
  if(inputManager.Keyboard->isKeyDown(OIS::KC_ESCAPE))
    return 1;

  //przyspieszanie
  int multiplier=1;
  if(inputManager.Keyboard->isModifierDown(OIS::Keyboard::Shift))
    multiplier=2;

  //lewo
  if(inputManager.Keyboard->isKeyDown(OIS::KC_A))
    ogre.Camera->moveRelative(Ogre::Vector3(-0.1*multiplier,0,0));
 
  //prawo
  if(inputManager.Keyboard->isKeyDown(OIS::KC_D))
    ogre.Camera->moveRelative(Ogre::Vector3(0.1*multiplier,0,0));
 
  //góra
  if(inputManager.Keyboard->isKeyDown(OIS::KC_W))
    ogre.Camera->moveRelative(Ogre::Vector3(0,0,-0.1*multiplier));
   
  //dół
  if(inputManager.Keyboard->isKeyDown(OIS::KC_S))
    ogre.Camera->moveRelative(Ogre::Vector3(0,0,0.1*multiplier));

  //spacja
  if(inputManager.Keyboard->isKeyDown(OIS::KC_SPACE))
    ogre.Camera->moveRelative(Ogre::Vector3(0,0.1*multiplier,0));

  //ctrl
  if(inputManager.Keyboard->isKeyDown(OIS::KC_LCONTROL))
    ogre.Camera->moveRelative(Ogre::Vector3(0,-0.1*multiplier,0));

  OIS::MouseState mouse=inputManager.Mouse->getMouseState();
  
  //Obrót po Z jest globalny, a po X lokalny, stąd trzeba pilnować kolejności
  ogre.Camera->setOrientation(
                              Ogre::Quaternion(256,0,0,-mouse.X.rel)
                              *ogre.Camera->getOrientation()
                              *Ogre::Quaternion(256,-mouse.Y.rel,0,0)
                              );

  if(mouse.buttonDown(OIS::MB_Left))
    {
      Ogre::Vector3 pos=ogre.Camera->getPosition();
      Ogre::Vector3 z=ogre.Camera->getDirection();
      pos+=20*z;
      Suzanne s(ogre,pos);
      s.Rotate=true;
      MonkeyList.push_back(s);
    }

  return 0;
}

void Tick(unsigned long delta)
{
  for(Suzanne s : MonkeyList)
    s.Tick(delta);
}

int main()
{
  TinyOgre ogre;
  InputManager InputManager(&ogre);

  for(int i =1;i<101;i++)
    {
      if(i%2)
        MonkeyList.push_back(Suzanne(ogre,Ogre::Vector3(i*3,0,0)));
      
      if(i%3)
        MonkeyList.push_back(Suzanne(ogre,Ogre::Vector3(0,i*3,0)));

      if(i%5)
        MonkeyList.push_back(Suzanne(ogre,Ogre::Vector3(0,0,i*3)));
    }

  Ogre::Timer timer;

  try
    {
      while(true)
        {
          // Pump window messages for nice behaviour
          Ogre::WindowEventUtilities::messagePump();

          if(ogre.Window->isClosed())
            {
              return false;
            }

          if(events(InputManager, ogre)==1)
            break;


          Tick(timer.getMilliseconds());
          timer.reset();

          // Render a frame
          if(!ogre.OgreRoot->renderOneFrame()) break;
        }
    }
  catch( Ogre::Exception& e ) 
    {
      std::cerr << "An exception has occured: " <<e.getFullDescription().c_str() << std::endl;
    }
}
