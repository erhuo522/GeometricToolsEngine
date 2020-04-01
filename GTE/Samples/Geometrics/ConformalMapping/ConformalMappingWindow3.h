// David Eberly, Geometric Tools, Redmond WA 98052
// Copyright (c) 1998-2020
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
// https://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// Version: 4.0.2019.08.13

#pragma once

#include <Applications/Window3.h>
using namespace gte;

class ConformalMappingWindow3 : public Window3
{
public:
    ConformalMappingWindow3(Parameters& parameters);

    virtual void OnIdle() override;
    virtual bool OnCharPress(unsigned char key, int x, int y) override;

private:
    // These are known for the file Brain_V4098_T8192.binary.
    enum
    {
        NUM_BRAIN_VERTICES = 4098,
        NUM_BRAIN_TRIANGLES = 8192,
    };

    bool SetEnvironment();

    // Load the brain data set, scale it for numerical stability of the
    // conformal mapping and generate colors based on mean curvatures at the
    // vertices.
    void LoadBrain(std::vector<Vector3<float>>& positions,
        std::vector<Vector4<float>>& colors, std::vector<unsigned int>& indices);

    void CreateScene();

    struct Vertex
    {
        Vector3<float> position;
        Vector4<float> color;
    };

    std::shared_ptr<RasterizerState> mWireState;
    std::shared_ptr<Node> mScene;
    std::shared_ptr<Node> mMeshNode;
    std::shared_ptr<Node> mSphereNode;
    std::shared_ptr<Visual> mMesh;
    std::shared_ptr<Visual> mSphere;
    float mExtreme;
};
