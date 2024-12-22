//
// Created by neil on 12/20/24.
//

#include "ofxHackyFBXOld.h"
#include "DrawScene.h"

void ofxHackyFBXOld::loadFBX(const string& filename)
{
    string fullPath = ofToDataPath(filename);
    sceneContext = make_shared<SceneContext>(fullPath.c_str(), ofGetWidth(), ofGetHeight(), true);
    if (!sceneContext->LoadFile()) ofLogError("ofxHackyFBXOld") << "Failed to load " << fullPath;
}

void ofxHackyFBXOld::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Test if the scene has been loaded yet.
    if (sceneContext->GetStatus() != SceneContext::UNLOADED && sceneContext->GetStatus() != SceneContext::MUST_BE_LOADED)
    {
        glPushAttrib(GL_ENABLE_BIT);
        glPushAttrib(GL_LIGHTING_BIT);
        glEnable(GL_DEPTH_TEST);
        // Draw the front face only, except for the texts and lights.
        glEnable(GL_CULL_FACE);

        FbxPose * lPose = NULL;
        //InitializeLights(mScene, mCurrentTime, lPose);
        FbxTime mCurrentTime = sceneContext->GetFrameTime();
        FbxAnimLayer * mCurrentAnimLayer = NULL;
        FbxAMatrix lDummyGlobalPosition;
        ShadingMode mShadingMode = ShadingMode::SHADING_MODE_SHADED;
        DrawNodeRecursive(sceneContext->GetScene()->GetRootNode(), mCurrentTime, mCurrentAnimLayer, lDummyGlobalPosition, lPose, mShadingMode);

        // Set the view to the current camera settings.
        //SetCamera(mScene, mCurrentTime, mCurrentAnimLayer, mCameraArray,
        //    mWindowWidth, mWindowHeight);

        /*FbxPose * lPose = NULL;
        if (sceneContext->Getpo mPoseIndex != -1)
        {
            lPose = mScene->GetPose(mPoseIndex);
        }

        // If one node is selected, draw it and its children.
        FbxAMatrix lDummyGlobalPosition;

        if (mSelectedNode)
        {
            // Set the lighting before other things.
            InitializeLights(mScene, mCurrentTime, lPose);
            DrawNodeRecursive(mSelectedNode, mCurrentTime, mCurrentAnimLayer, lDummyGlobalPosition, lPose, mShadingMode);
            DisplayGrid(lDummyGlobalPosition);
        }
        // Otherwise, draw the whole scene.
        else
        {
            InitializeLights(mScene, mCurrentTime, lPose);
            DrawNodeRecursive(mScene->GetRootNode(), mCurrentTime, mCurrentAnimLayer, lDummyGlobalPosition, lPose, mShadingMode);
            DisplayGrid(lDummyGlobalPosition);
        }*/

        glPopAttrib();
        glPopAttrib();
    }

    //DisplayWindowMessage();

    //return true;
}
