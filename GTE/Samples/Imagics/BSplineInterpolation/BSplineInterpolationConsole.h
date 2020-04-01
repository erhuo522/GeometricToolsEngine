// David Eberly, Geometric Tools, Redmond WA 98052
// Copyright (c) 1998-2020
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
// https://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// Version: 4.0.2019.08.13

#pragma once

#include <Applications/Console.h>
using namespace gte;

class BSplineInterpolationConsole : public Console
{
public:
    BSplineInterpolationConsole(Parameters& parameters);

    virtual void Execute() override;

private:
    bool SetEnvironment();

    void DoIntpBSplineUniform1();
    void DoIntpBSplineUniform2();
    void DoIntpBSplineUniform3();

    int mCacheMode;
    std::string mGTE4Path;
};
