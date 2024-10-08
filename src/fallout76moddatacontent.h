#ifndef FALLOUT76_MODDATACONTENT_H
#define FALLOUT76_MODDATACONTENT_H

#include <gamebryomoddatacontent.h>
#include <ifiletree.h>

class Fallout76ModDataContent : public GamebryoModDataContent
{
protected:
  enum Fallout76Content
  {
    CONTENT_MATERIAL = CONTENT_NEXT_VALUE
  };

public:
  Fallout76ModDataContent(MOBase::IGameFeatures const* gameFeatures)
      : GamebryoModDataContent(gameFeatures)
  {
    m_Enabled[CONTENT_SKYPROC] = false;
  }

  std::vector<Content> getAllContents() const override
  {
    auto contents = GamebryoModDataContent::getAllContents();
    contents.push_back(
        Content(CONTENT_MATERIAL, "Materials", ":/MO/gui/content/material"));
    return contents;
  }

  std::vector<int>
  getContentsFor(std::shared_ptr<const MOBase::IFileTree> fileTree) const override
  {
    auto contents = GamebryoModDataContent::getContentsFor(fileTree);
    for (auto e : *fileTree) {
      if (e->compare("materials") == 0) {
        contents.push_back(CONTENT_MATERIAL);
        break;  // Early break if you have nothing else to check.
      }
    }
    return contents;
  }
};

#endif  // FALLOUT76_MODDATACONTENT_H
