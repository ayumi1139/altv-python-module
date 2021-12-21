#include "resource.h"

bool PythonResource::Start()
{

    return true;
}

bool PythonResource::Stop()
{
    return Impl::Stop();
}

bool PythonResource::OnEvent(const alt::CEvent *ev)
{
    return Impl::OnEvent(ev);
}

void PythonResource::OnTick()
{
    Impl::OnTick();
}

void PythonResource::OnCreateBaseObject(alt::Ref<alt::IBaseObject> object)
{
    Impl::OnCreateBaseObject(object);
}

void PythonResource::OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object)
{
    Impl::OnRemoveBaseObject(object);
}
