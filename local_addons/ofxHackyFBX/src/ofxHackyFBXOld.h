#pragma once

#include "SceneContext.h"
#include "ofMain.h"

class ofxHackyFBXOld
{
public:
    void loadFBX(const string& filename);
    void draw();

private:
    shared_ptr<SceneContext> sceneContext;
};