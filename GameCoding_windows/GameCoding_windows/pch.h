#pragma once

#include "Types.h"
#include "Enums.h"
#include "Defines.h"
#include "Utils.h"

#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


#include <format>


// 메모리 릭 체크하는 것이 좋다
#define _CRTDEBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
// 밑에 줄 쓰면 파일의 몇번째 줄인지 추적할 수 있게 된다. 
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif