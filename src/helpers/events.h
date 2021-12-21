#pragma once

#include "SDK.h"
#include "../resource.h"

#define REGISTER_EVENT_HANDLER(type, name, returnType, decl, argsGetter) \
    static void On##name(asIScriptFunction* callback)                                                                      \
    {                                                                                                                      \
        GET_RESOURCE();                                                                                                    \
        resource->RegisterEventHandler(type, callback);                                                                    \
    }                                                                                                                      \
    static Event Event##name(type, #name, returnType, decl, argsGetter, [](asIScriptEngine* engine, DocsGenerator* docs) { \
        std::stringstream funcDef;                                                                                         \
        funcDef << returnType << " " << #name << "Callback(" << decl << ")";                                               \
        engine->RegisterFuncdef(funcDef.str().c_str());                                                                    \
        std::stringstream globalFunc;                                                                                      \
        globalFunc << "void On" << #name << "(" << #name << "Callback@ callback)";                                         \
        engine->RegisterGlobalFunction(globalFunc.str().c_str(), asFUNCTION(On##name), asCALL_CDECL);                      \
        docs->PushEventDeclaration(funcDef.str(), globalFunc.str());                                                       \
    });

namespace Helpers {}