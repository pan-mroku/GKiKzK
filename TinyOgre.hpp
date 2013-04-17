/*
  -----------------------------------------------------------------------------
  Filename:    TinyOgre.hpp
  -----------------------------------------------------------------------------

  This source file is part of the
  ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
  //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
  / \_// (_| | | |  __/  \  /\  /| |   <| |
  \___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
  |___/                              
  Tutorial Framework
  http://www.ogre3d.org/tikiwiki/
  -----------------------------------------------------------------------------
*/
#ifndef __TinyOgre_hpp_
#define __TinyOgre_hpp_

#include <OgreRoot.h>
#include <OgreCamera.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>

class TinyOgre
{
public:
  Ogre::Root* OgreRoot;
  Ogre::Camera* Camera;
  Ogre::SceneManager* SceneMgr; //http://www.ogre3d.org/docs/manual/manual_7.html#The-SceneManager-object
  Ogre::RenderWindow* Window;

  TinyOgre(void);
  virtual ~TinyOgre(void);
};

#endif // #ifndef __TinyOgre_hpp_
