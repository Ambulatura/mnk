#pragma once

#ifdef MNK
    #define MNK_API
#else
    #ifdef MNK_DLL
	    #define MNK_API __declspec(dllexport)
    #else
	    #define MNK_API __declspec(dllimport)
    #endif
#endif
