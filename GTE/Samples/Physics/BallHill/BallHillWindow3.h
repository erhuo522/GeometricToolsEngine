// David Eberly, Geometric Tools, Redmond WA 98052
// Copyright (c) 1998-2020
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
// https://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// Version: 4.0.2019.08.13

#pragma once

#include <Applications/Window3.h>
#include <Graphics/MeshFactory.h>
#include "PhysicsModule.h"
using namespace gte;

//#define BALL_HILL_SINGLE_STEP

class BallHillWindow3 : public Window3
{
public:
    BallHillWindow3(Parameters& parameters);

    virtual void OnIdle() override;
    virtual bool OnCharPress(unsigned char key, int x, int y) override;

private:
    bool SetEnvironment();
    void InitializeModule();
    void CreateScene();
    void CreateGround();
    void CreateHill();
    void CreateBall();
    void CreatePath();
    Vector4<float> UpdateBall();
    void PhysicsTick();
    void GraphicsTick();

    struct Vertex
    {
        Vector3<float> position;
        Vector2<float> tcoord;
    };

    VertexFormat mVFormat;
    MeshFactory mMeshFactory;
    std::shared_ptr<Visual> mGround, mHill, mBall, mPath;
    PhysicsModule mModule;
};
