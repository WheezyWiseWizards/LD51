//
// Created by Winter on 01/10/2022.
//

#ifndef LD51_CLIENT_TOPDOWNSCREEN_H
#define LD51_CLIENT_TOPDOWNSCREEN_H

#include <WIZ/game/Screen.h>
#include <unordered_map>
#include <SFML/Graphics/RenderTexture.hpp>
#include "world/World.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class TopDownScreen : public wiz::Screen, public wiz::WindowListener, public wiz::InputListener {
	std::string name = "TopDownScreen";

	World world;
	std::unordered_map<TerrainType, sf::Texture*> terrain_textures;
	sf::Sprite terrain_sprite;
	sf::Sprite heart_sprite;
	sf::RenderTexture frameBuffer;
    sf::Shader* spookyShader = nullptr;

    float timeAccumulator = 0.0;
    float tenSecAccumulator = 0.0;

    void processInput();

public:
	explicit TopDownScreen(wiz::Game& game);

	void drawWorld(sf::RenderTarget& target);

	void tick(float delta) override;

	void render(sf::RenderTarget& target) override;

	void show() override;

	void hide() override;

	const std::string& getName() const override;

	void windowClosed() override;
};


#endif //LD51_CLIENT_TOPDOWNSCREEN_H