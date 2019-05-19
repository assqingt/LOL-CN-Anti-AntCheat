// header.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>

// stl头文件
#include <string>
#include <memory>
#include <algorithm>

// 字符串加密
#include <encstr/string.hpp>
#include <encstr/cbc.hpp>
#include <encstr/ciphers/xor_cipher.hpp>
