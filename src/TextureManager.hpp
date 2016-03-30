//
// Created by Clark Burton Chambers on 3/28/16.
//

#ifndef CLARKSOULS_TEXTUREMANAGER_HPP
#define CLARKSOULS_TEXTUREMANAGER_HPP

#include "Includes.hpp"

// General flow:
//  -Add a texture to the map
//  -Get texture from map.
//  -Use texture. gg.

// NOTE(clark): Should we use pointers for the map? or just textures.
// NOTE(clark_cont): sf::Sprites take a const sf:Texture for their argument anyways.

class TextureManager {
private:

    std::map<std::string, sf::Texture*> m_textureMap;

public:

    // Constructors and destructors.
    TextureManager();
    ~TextureManager();

    // Adds textures to the texture map. These can be referenced for
    // sprites you may create in the future.
    //      Exceptions:
    //          e_manager_obj_exists: Texture already exists in the map.
    void AddTexture(std::string id, sf::Texture *texture);

    // Gets a texture from the map. YOu can use this texture pointer
    // to make sprites look neat!
    //      Exceptions:
    //          e_manager_obj_dne: Texture does not exist in map.
    sf::Texture *GetTexture(std::string id);


    // Removes a texture from the map. Forever. :'c.
    //      Exceptions:
    //          e_manager_obj_dne: Texture does not exist in the map
    void RemoveTexture(std::string id);

};


#endif //CLARKSOULS_TEXTUREMANAGER_HPP
