//
// Created by Clark Burton Chambers on 3/28/16.
//

#include "TextureManager.hpp"

TextureManager::TextureManager()
{

}

void TextureManager::AddTexture(std::string id, sf::Texture *texture)
{
    // Texture can't exist under ID
    check(m_textureMap.find(id) == m_textureMap.end(), e_manager_obj_exists,
            "Texture: %s, already exists!", id.data())

    m_textureMap[id] = texture;
}

sf::Texture *TextureManager::GetTexture(std::string id)
{
    // Texture has to exist so we can get it
    check(m_textureMap.find(id) != m_textureMap.end(), e_manager_obj_dne,
            "Texture: %s, does not exist", id.data())

    return m_textureMap[id];
}

void TextureManager::RemoveTexture(std::string id)
{
    // Texture must exist so we can remove it
    check(m_textureMap.find(id) != m_textureMap.end(), e_manager_obj_dne,
            "Texture: %s, does not exist", id.data())

    m_textureMap.erase(id);
}

