#include "suzanne.hpp"

Suzanne::Suzanne(TinyOgre& ogre, const Ogre::Vector3& position, const std::string& meshFile):ogre(&ogre),Rotate(false)
{
  Ogre::Entity* entity=ogre.SceneMgr->createEntity(meshFile);
  Node=ogre.SceneMgr->getRootSceneNode()->createChildSceneNode();
  Node->setPosition(position);
  Node->attachObject(entity);
}

void Suzanne::Tick(unsigned long delta)
{
  if(Rotate)
    {
      float multiplier=delta/1000.0;
      Node->rotate(Ogre::Quaternion(1,0,0,multiplier));
    }
}
