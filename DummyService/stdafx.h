// Copyright 2008 - 2020 BeyondTrust Corp. All rights reserved.

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"
#include "resource.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#define _ATL_NO_COM_SUPPORT 

#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <atltime.h>
#include <Windows.h>