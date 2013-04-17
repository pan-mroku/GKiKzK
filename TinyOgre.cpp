/*
  -----------------------------------------------------------------------------
  Filename:    TinyOgre.cpp
  -----------------------------------------------------------------------------

  This source file is part of the
  ___                 __B[B[B    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
  //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
  / \_// (_| | | |  __/  \  /\  /| |   <| |
  \___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
  |___/                              
  Tutorial Framework
  http://www.ogre3d.org/tikiwiki/
  -----------------------------------------------------------------------------
*/
#include "TinyOgre.hpp"

#include <OgreLogManager.h>
#include <OgreViewport.h>
#include <OgreConfigFile.h>
#include <OgreEntity.h>

//-------------------------------------------------------------------------------------
TinyOgre::TinyOgre(void)
{

  OgreRoot = new Ogre::Root();

  if(OgreRoot->restoreConfig() || OgreRoot->showConfigDialog())
    Window = OgreRoot->initialise(true, "TinyOgre Render Window"); //koniecznie tuż pod konstruktorem root!
  else
      throw -1;

  SceneMgr = OgreRoot->createSceneManager(Ogre::ST_GENERIC);
  SceneMgr->setAmbientLight(Ogre::ColourValue(0.4, 0.4, 0.4));
  Ogre::Light* l = SceneMgr->createLight("MainLight");
  l->setPosition(20,-80,50);

  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("Suzanne", "FileSystem");
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);//Ponoć niektóre API to omijają, więc warto dodać
  
  Camera = SceneMgr->createCamera("PlayerCam");
  Camera->setPosition(Ogre::Vector3(10,-50,10));
  Camera->setOrientation(Ogre::Quaternion(1,1,0,0));
  Camera->setNearClipDistance(0.1);

  Ogre::Viewport* vp = Window->addViewport(Camera);
  vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
  Camera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}
//-------------------------------------------------------------------------------------
TinyOgre::~TinyOgre(void)
{
  delete OgreRoot;
}
