// David Eberly, Geometric Tools, Redmond WA 98052
// Copyright (c) 1998-2020
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
// https://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// Version: 4.0.2019.08.13

uniform PVWMatrix
{
    mat4 pvwMatrix;
};

layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec3 modelNormal;
layout(location = 0) out vec3 vertexPosition;
layout(location = 1) out vec3 vertexNormal;

void main()
{
    vertexPosition = modelPosition;
    vertexNormal = modelNormal;
#if GTE_USE_MAT_VEC
    gl_Position = pvwMatrix * vec4(modelPosition, 1.0f);
#else
    gl_Position = vec4(modelPosition, 1.0f) * pvwMatrix;
#endif
}
