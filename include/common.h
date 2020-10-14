//
// Created by Alex Korzh on 14.10.2020.
//

#pragma once

#include <string>

const int BadDescriptor = -1;

using ReceiveCallback = void(*)(const std::string&);