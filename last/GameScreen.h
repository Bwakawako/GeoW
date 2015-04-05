#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include<SFML/Graphics.hpp>

class ScreenBase
{
public:
	ScreenBase();
	~ScreenBase();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(float elapsedTime);
	virtual void Draw(sf::RenderWindow &window);
protected:
	/*InputManager input;
	std::vector<int> keys;*/
};

#endif
