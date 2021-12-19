#include "main.h"

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);

    auto runtime = new PythonRuntime();
    core->RegisterScriptRuntime("pythonModule", runtime);

    core->LogInfo("Loaded python module!");

    return true;
}