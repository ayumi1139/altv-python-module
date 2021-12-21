#pragma once

#include "main.h"

class PythonRuntime;
class PythonResource : public alt::IResource::Impl
{
    PythonRuntime* runtime;
    alt::IResource* resource;

public:
    PythonResource(PythonRuntime* runtime, alt::IResource* resource) : runtime(runtime), resource(resource) { }

    bool MakeClient(alt::IResource::CreationInfo* info, alt::Array<alt::String> files)
    {
        return true;
    }

    bool Start() override;
    bool Stop() override;

    bool OnEvent(const alt::CEvent* ev) override;

    void OnTick() override;

    void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;

    void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;

    alt::IResource* GetIResource() const
    {
        return resource;
    }

    PythonRuntime* GetRuntime() const
    {
        return runtime;
    }
};