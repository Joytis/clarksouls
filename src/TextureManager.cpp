//
// Created by Clark Burton Chambers on 3/28/16.
//

#include "TextureManager.hpp"

TextureManager::TextureManager()
{

}

void TextureManager::AddTexture(std::string id, sf::Texture *texture)
{
    if(m_textureMap.find(id) == m_textureMap.end()) {
        m_textureMap[id] = texture;
    } else {
        throw new e_manager_obj_exists;
    }
}

sf::Texture *TextureManager::GetTexture(std::string id)
{
    if(m_textureMap.find(id) != m_textureMap.end()) {
        return m_textureMap[id];
    } else {
        throw new e_manager_obj_dne;
    }
}

void TextureManager::RemoveTexture(std::string id)
{
    if(m_textureMap.find(id) != m_textureMap.end()) {
        m_textureMap.erase(id);
    } else {
        throw new e_manager_obj_dne;
    }
}

