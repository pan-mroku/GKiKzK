#ifndef SUZANNE_HPP
#define SUZANNE_HPP

#include "TinyOgre.hpp"
#include <OgreEntity.h>
#include <string>

class Suzanne
{
public:
  Ogre::SceneNode* Node;
  bool Rotate;

  Suzanne(TinyOgre& ogre, const Ogre::Vector3& position=Ogre::Vector3(0,0,0), const std::string& meshFile="Suzanne.mesh");

  void Tick(unsigned long delta);

protected:
  TinyOgre* ogre;
};

#endif
