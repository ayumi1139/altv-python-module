#pragma once

#include "SDK.h"

#include "resource.h"

class PythonRuntime : public alt::IScriptRuntime
{
    std::unordered_map<alt::IResource*, PythonResource*> resources;

public:
    PythonRuntime() { }

    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override
    {
        return new PythonResource(this, resource);
    }

    void DestroyImpl(alt::IResource::Impl* impl) override
    {
        PythonResource* resource = dynamic_cast<PythonResource*>(impl);
        delete resource;
    }

    static PythonRuntime& GetInstance()
    {
        static PythonRuntime _instance;
        return _instance;
    }
};