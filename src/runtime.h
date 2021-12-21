#pragma once

#define ALT_SERVER_API

#include "main.h"

#include "resource.h"

class PythonRuntime : public alt::IScriptRuntime
{
    std::unordered_map<alt::IResource*, PythonResource*> resources;

public:
    PythonRuntime();

    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;

    void DestroyImpl(alt::IResource::Impl* impl) override;

    void OnTick() override;
    void OnDispose() override;

    PythonResource* GetResource(alt::IResource* resource)
    {
        auto result = resources.find(resource);
        if (result == resources.end()) return nullptr;
        return result->second;
    }

    static PythonRuntime& GetInstance()
    {
        static PythonRuntime _instance;
        return _instance;
    }
};