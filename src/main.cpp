#include "main.h"

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);

    auto& runtime = PythonRuntime::GetInstance();
    core->RegisterScriptRuntime("python-module", &runtime);

    core->LogInfo("Python module : script runtime registered");

    return true;
}

EXPORT uint32_t GetSDKVersion()
{
    return alt::ICore::SDK_VERSION;
}