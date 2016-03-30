//
// Created by Clark Burton Chambers on 3/30/16.
//

#include "FontManager.hpp"

FontManager::FontManager() {


}

void FontManager::AddFont(std::string id, sf::Font *font)
{
    if(m_fontMap.find(id) == m_fontMap.end()) {
        m_fontMap[id] = font;
    } else {
        throw new e_manager_obj_exists;
    }
}

sf::Font *FontManager::GetFont(std::string id)
{
    if(m_fontMap.find(id) != m_fontMap.end()) {
        return m_fontMap[id];
    } else {
        throw new e_manager_obj_dne;
    }
}

void FontManager::RemoveFont(std::string id)
{
    if(m_fontMap.find(id) != m_fontMap.end()) {
        m_fontMap.erase(id);
    } else {
        throw new e_manager_obj_dne;
    }
}
