#include "runtime.h"

PythonRuntime::PythonRuntime()
{
    python::initialize_interpreter(false);
}

alt::IResource::Impl* PythonRuntime::CreateImpl(alt::IResource* impl)
{
    auto* resource = new PythonResource(this, impl);
    resources.insert({ impl, resource });
    return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl *impl)
{
    auto* resource = dynamic_cast<PythonResource*>(impl);

    if (resource != nullptr)
    {
        resources.erase(resource->GetIResource());
        delete resource;
    }
}


void PythonRuntime::OnTick()
{
    python::finalize_interpreter();

    IScriptRuntime::OnTick();
}

void PythonRuntime::OnDispose()
{
    IScriptRuntime::OnDispose();
}
