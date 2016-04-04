//
// Created by Clark Burton Chambers on 3/14/16.
//

#ifndef CLANDREWSOULS_INCLUDES_HPP
#define CLANDREWSOULS_INCLUDES_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <stack>
#include <string>
#include <thread>
#include <vector>

#include "dbg.hpp"

#include "Input.hpp"
#include "StateSystem.hpp"
#include "TextureManager.hpp"
#include "FontManager.hpp"

// Exceptions!
#include "exceptions/BasicExceptions.hpp"
#include "exceptions/StateSystemExceptions.hpp"
#include "exceptions/ManagerExceptions.hpp"


#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))



#endif //CLANDREWSOULS_INCLUDES_HPP
