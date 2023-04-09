#ifndef FALLOUT4_MODATACHECKER_H
#define FALLOUT4_MODATACHECKER_H

#include <gamebryomoddatachecker.h>

class Fallout76ModDataChecker : public GamebryoModDataChecker
{
public:
  using GamebryoModDataChecker::GamebryoModDataChecker;

protected:
  virtual const FileNameSet& possibleFolderNames() const override {
    static FileNameSet result{
      "interface", "meshes", "music", "scripts", "sound", "strings", "textures", "trees", "video", "materials", "distantlod", "asi", "Tools", "MCM", "distantland", "mits", "dllplugins", "shadersfx", "Root"
    };
    return result;
  }
  virtual const FileNameSet& possibleFileExtensions() const override {
    static FileNameSet result{
      "esp", "esm", "esl", "ba2", "modgroups"
    };
    return result;
  }
};

#endif // FALLOUT4_MODATACHECKER_H
